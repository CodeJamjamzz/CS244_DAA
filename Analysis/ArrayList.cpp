#include <iostream>
using namespace std; 

class List{
    public:
    virtual void addFirst(int num) = 0;
    virtual void addLast(int num) = 0;
    virtual void removeFirst() = 0;
    virtual void removeLast() = 0;
    virtual int getNum(int pos) = 0;
    virtual int getPos(int num) = 0;
    virtual void addAt(int num, int pos) = 0;
    virtual int removeAt(int pos) = 0;

    virtual int remove(int num) = 0;
};

class ArrayList {
    int size;
    int capacity;
    int *array;

    public:
    ArrayList(){ // Final: 5

        size = 0; // 1
        capacity = 5; // 1
        array = (int*) calloc(capacity, sizeof(int)); // 4
    }

    void dynamicIncrease(){ // Final: 7

        capacity = capacity * 1.5; // 2 
        array = (int*) realloc(array, capacity * sizeof(int)); // 5
    }

    void dynamicDecrease(){ // Final: 6
        capacity /= 2; // 1
        array = (int*) realloc(array, capacity * sizeof(int)); // 5
    }

    void addLast(int num){ // Final: 11
        if(size == capacity){  // 1
            dynamicIncrease(); // 7
        }
        array[size++] = num; // 3
    }
    
    void addFirst(int num){ // Final: 6n + 13 
        if(size == capacity){ // 1
            dynamicIncrease(); // 7
        }

        for(int i = size; i > 0; i--){  // 1 n+1 n n n n n = 6n + 2  
            array[i] = array[i-1];
        }

        array[0] = num; // 2
        size++; // 1
    }

    void addAt(int num, int pos){ // final = 6n + 10
        if(pos >= size){ // 1
            throw new logic_error("array out of bounds");
        }
    
        int p = pos - 1; // 2
        for(int i = size; i > p; i++){ // 1 n n-1 n-1 n-1 n-1 n-1 = 6n + 4
            array[i] = array[i-1]; 
        }
        size++; // 1
        array[p] = num; // 2
        return;
    }

    void print(){ // Final: 
        for(int i = 0 ; i < size; i++){ // 1 n+1 n n 
            cout << array[i] << " ";
        }
        cout << endl;
        return;
    }

    void removeFirst(){
        if(size == 0){ // 1
            throw new logic_error("Empty Array!\n");
        }
        for(int i = 0; i < size; i++){ // 1 n+1 n n n n n = 6n + 2
            array[i] = array[i+1];
        }
        size--; // 1
        if(size <= capacity / 2){ // 2
            dynamicDecrease(); // 6
        }
    }

    void removeLast(){ // Final: 11
        if(size == 0){ // 1
            throw new logic_error("Empty Array!\n");
        }
        array[size--]; // 2
        if(size <= capacity / 2){ // 2
            dynamicDecrease(); // 6
        }
    }

    int removeAt(int pos){ // Final: 6n + 4
        if(pos >= size){ // 1
            throw new logic_error("array out of bounds");
        }
        int deleted = array[pos-1]; // 3
        int isize = size - 1; // 2
        for(int i = pos - 1; i < isize; i++){ // 2 n n-1 n-1 n-1 n-1 n-1 = 6n - 3
            array[i] = array[i+1];
        }
        size--; // 1
        dynamicDecrease();
        return deleted;
    }

    int remove(int num){ // Final: 10n + 11
        int deleted = -1; // 1
        int index = -1; // 1

        for(int i = 0; i < size; i++){ // 1 
            if(array[i] == num){
                index = i;
                break;
            }
        }

        if (index == -1) {
            return -1; // Element not found
        }

        deleted = array[index]; // 2
        int isize = size - 1;
        for(int i = index; i < isize; i++){ // 1 n+1 n n n n n = 6n + 2
            array[i] = array[i+1];
        }

        size--; // 1
        return deleted;
    
    }

    int getNum(int pos){ // Final: 
        if(pos >= size || pos < 0){  // 3
            cout << "Array is out of bounds";
            return -1;
        }
        int rem = pos - 1; // 2
        return array[rem]; // 1
    }

    int getPos(int num){ // 4n + 2
        for(int i = 0; i < size; i++){ // 1 n+1 n n n = 4n + 2
            if(array[i] == num){
                return i + 1;
            }
        }
    }

    bool isEmpty(){ // 1
        return size == 0; // 1
    }
};

int main(){
    ArrayList *list = new ArrayList();

    char op;
    int num;

    do {

        cout << "Enter option: ";
        cin >> op;

        switch(op){
            case 'f':
                cout << "Enter number: ";
                cin >> num;
                list->addFirst(num);
                break;
            case 'l':
                cout << "Enter number: ";
                cin >> num;
                list->addLast(num);
                break;
            case 'F':
                list->removeFirst();
                break;
            case 'L':
                list->removeLast();
                break;
            case 'p':
                cout << "Enter position: ";
                cin >> num;
                cout << list->getNum(num) << endl;
                break;
            case 'P':
                cout << "Enter number: ";
                cin >> num;
                cout << list->getPos(num) << endl;
                break;
            case 'd':
                list->print();
                break;
        }
    } while(op != 'x');
}