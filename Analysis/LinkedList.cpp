#include <iostream>
using namespace std; 

class List{
    public:
    virtual void add(int num) = 0;
    virtual int getPos(int num) = 0;
    virtual void addAt(int num, int pos) = 0;
    virtual int removeAt(int pos) = 0;
    virtual int remove(int num) = 0;
};

struct node {
    int elem;
    node* next;
    node* prev;
};

class Linkedlist {
    node* head;
    node* tail;
    int size;

    public: 
    Linkedlist(){
        size = 0;
        head = (node*) malloc(sizeof(node));
        tail = (node*) malloc(sizeof(node));
        head->next = tail;
        tail->prev = head;
    }

    void addbetween(int num, node* pred, node* succ){ // Final: 13
        node* newnode = new node(); // 2
        newnode->elem = num; // 2

        succ->prev = newnode; // 2
        pred->next = newnode; // 2

        newnode->prev = pred; // 2
        newnode->next = succ; // 2
        size++; // 1
        return;
    }

    int removebetween(node* n){ // Final: 11
        node* pred = n->prev; // 2
        node* succ = n->next; // 2

        int ret = n->elem; // 2
        pred->next = succ; // 2
        succ->prev = pred; // 2
        free(n); 
        size--; // 1
        return ret;
    }

    void add(int num){
        addbetween(num, tail->prev, tail);
    }

    int getPos(int num){ // Final: 5n + 3
        node* temp = head; // 1
        int i = 0; // 1
        while(temp != tail){ // n+1 n n n n n = 5n + 1
            if(temp->elem == num){
                break;
            }
            i++;
            temp = temp->next;
        }

        return i;
    }
    
    int remove(int num){ // Final: 5n + 5
        node* curr = head->next; // 2
        int pos = 1; // 1
        int removed = -1; // 1
        while(curr != tail){ // n+1 n n n n 
            if(curr->elem  == num){
                removed = removebetween(curr);
                break;
            }
            curr = curr->next;
        }

        return removed;
    }
    
    void print(){
        node* temp = head->next;
        while(temp != tail){
            cout << temp->elem << " ";
            temp = temp->next;
        }
    }
};

int main(){
    Linkedlist *list = new Linkedlist();

    char op;
    int num;

    do {

        cout << "Enter option: ";
        cin >> op;

        switch(op){
            case 'f':
                cout << "Enter number: ";
                cin >> num;
                list->add(num);
                break;
            case 'L':
                cout << "Enter number: ";
                cin >> num;
                list->remove(num);
                break;
            case 'p':
                list->print();
                break;
            case 'P':
                cout << "Enter num: ";
                cin >> num;
                cout << list->getPos(num);
                break;
        }
    } while(op != 'x');
}

// int ctr = 1;
//         node* temp = head;
        
//         if(pos == 1){
//             addFirst(num);
//             return;
//         } else if (pos > size ) {
//             addLast(num);
//             return;
//         } 
        
//         while(ctr < pos){
//             if(ctr == pos){
//                 addBetween(temp, num); 
//             }
            
//             ctr++;
//             temp = temp->next;
//         }