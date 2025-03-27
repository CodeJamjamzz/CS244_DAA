#include <iostream>
using namespace std;

struct node{
    int elem;
    node* next;
};

class LinkedListStack {
    int size;
    node* head;
    node* tail;

    public:
    LinkedListStack(){
        size = 0;
        head = new node();
        tail = new node();
    }

    void addHead(int num, node* succ){
        node* newnode = new node();
        newnode->elem = num;
        newnode->next = succ;
        head = newnode;
        return;
    }

    void push(int num){
        size++;
        node* newnode = new node();
        newnode->elem = num;
        newnode->next = head;
        head = newnode;
    }

    int pop(){
        node* removed = head;
        int num = head->elem;
        head = head->next;
        size--;
        delete removed;
        return num;
    }

    bool isEmpty(){
        return size == 0;
    }

    int top(){
        return head->elem;
    }

    void print(){
        node* temp = head;
        while(temp->next){
            cout << temp->elem << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedListStack *stack = new LinkedListStack();
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