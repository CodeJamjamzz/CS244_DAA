#include <iostream> 
#include <cmath>
using namespace std;

class ArrayStack {
    int _size;
    int capacity;
    int* array;

    public:
    
    ArrayStack(){
        _size = 0;
        capacity = 5;
        array = (int*) malloc(capacity * sizeof(int));
    }

    void dynamicIncrease(){ // T(n) = 9
        if(_size >= capacity){ // 1
            capacity = ceil(capacity * 1.5); // 3
            array = (int*) realloc(array, sizeof(int) * capacity); //5
        }
    }

    void dynamicDecrease(){
        if(_size <= capacity * 2.0/3.0){
            capacity -= floor(capacity * 0.25);

            if(capacity <= 5){
                capacity = 5;
            }

            array = (int*) realloc(array, sizeof(int) * capacity);
        }
    }

    int top(){
        return array[_size - 1];
    }

    void push(int num){ // T(n) = 12
        dynamicIncrease(); // 9
        array[_size++] = num ; // 3
    } 

    int pop(){
        int removed = array[--_size];
        dynamicDecrease();
        return removed;
    }

    bool isEmpty(){
        return _size == 0;
    }

    void print(){
        for(int i = 0; i < _size; i++){
            cout << array[i] << ' ';
        }
        cout << endl;
    }
};

int main(){
    ArrayStack *stack = new ArrayStack();
    int num;
    char choice;

    do{
        cout << "Enter option: ";
        cin >> choice;

        switch(choice){
            case 'a':
                cout << "Etner number: ";
                cin >> num;

                stack->push(num);
                break;
            case 'r':
                cout << "Removed: " << stack->pop() << endl;
                break;
            case 't':
                cout << "Top: " << stack->top() << endl;
                break;
            case 'p':
                stack->print();
                break;
            case 'e':
                stack->isEmpty()? cout << "yes" : cout << "no";
                cout << endl;
                break;
        }

    } while(choice != 'x');
}