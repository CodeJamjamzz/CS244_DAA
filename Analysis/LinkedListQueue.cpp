#include <iostream> 
using namespace std;

struct node{
    int elem;
    // node* prev;
    node* next;
};

class LinkedListQueue {
    int size;
    node* head;
    node* tail;

    public:
    LinkedListQueue(){
        size = 0;
        head = new node();
        tail = new node();
        // head->next = tail;
        // tail->prev = head;
    }

    // void addbetween(int num, node* prev, node* succ){
    //     node* newnode = new node();
    //     newnode->elem = num;

    //     prev->next = newnode;
    //     succ->prev = newnode;

    //     newnode->next = succ;
    //     newnode->prev = prev;
    //     size++;
    // }

    void enqueue(int num){
        // addbetween(num, head, head->next);
        node* newnode = new node();
        newnode->elem = num;
        if(size == 0){
            head = newnode;
            tail = newnode;
            size++;
            return;
        }

        tail->next = newnode;
        tail = newnode;
        size++;
        return;
    }

    int dequeue(){
        if(size == 0) return -1;
        int removed = head->elem;
        head = head->next;
        size--;
        return removed;
    }

    int first(){
        return head->elem;
    }

    int _size(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void print(){
        node* curr = head;
        while(curr != tail->next){
            cout << curr->elem << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedListQueue *stack = new LinkedListQueue();
    int num;
    char choice;

    do{
        cout << "Enter option: ";
        cin >> choice;

        switch(choice){
            case 'a':
                cout << "Etner number: ";
                cin >> num;

                stack->enqueue(num);
                break;
            case 'r':
                cout << "Removed: " << stack->dequeue() << endl;
                break;
            case 't':
                cout << "Top: " << stack->first() << endl;
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