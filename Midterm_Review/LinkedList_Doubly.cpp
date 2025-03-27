#include <iostream>
using namespace std;

struct node {
    int elem;
    node* prev;
    node* next;
};

class DoublyLinkedList {
    node* head;
    node* tail;
    int size;

    public:
    DoublyLinkedList(){
        head = new node();
        tail = new node();
        size = 0;
        head->next = tail;
        tail->prev = head;
    }

    void addBetween(int num, node* prev, node* succ){
        node* newnode = new node();
        newnode->elem = num;

        node* before = prev;
        node* after = succ;

        before->next = newnode;
        newnode->prev = before;

        after->prev = newnode;
        newnode->next = after;
        size++;
        return;
    }

    void addFirst(int num){
        addBetween(num, head, head->next);
    }

    void addLast(int num){
        addBetween(num, tail->prev, tail);
        return;
    }

    int removeBetween(node* currentnode){
        node* before = currentnode->prev;
        node* after = currentnode->next;

        node* remove = currentnode;
        int num = currentnode->elem;
        before->next = after;
        after->prev = before;
        size--;
        delete remove;
        return num;
    }

    int removeFirst(){
        if(size == 0){
            throw logic_error("cannot remove empty list");
        }
        return removeBetween(head->next);
    }

    int removeLast(){
        if(size == 0){
            throw logic_error("cannot remove empty list");
        }
        return removeBetween(tail->prev);
    }

    int get(int pos){
        if (pos < 1 || pos > size) {
            throw out_of_range("Index out of bounds");
        }
    
        node* temp;
    
        if (pos > size / 2) {
            temp = tail->prev; 
            int n = size - pos;
    
            for (int i = 0; i < n; i++) {
                temp = temp->prev;
            }
        } else {
            temp = head->next;  
            for (int i = 1; i < pos; i++) {  
                temp = temp->next;
            }
        }
    
        return temp->elem;
    }

    void print(){
        node* temp = head->next;
        while(temp != tail){
            cout << temp->elem << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    DoublyLinkedList *list = new DoublyLinkedList();

    char choose;
    int num;

    do {

        cout << "Enter option: ";
        cin >> choose;

        switch (choose){
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
                cout << list->removeFirst() << endl;
                break;
            case 'L':
                cout << list->removeLast() << endl;
                break;
            case 'g':
                cout << "Enter number: ";
                cin >> num;
                cout << list->get(num) << endl;
                break;
            case 'p':
                list->print();
                break;
        }
    } while(choose != 'x');
}