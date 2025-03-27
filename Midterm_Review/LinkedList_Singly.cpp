#include <iostream>
using namespace std;

struct node {
    int elem;
    node* next;
};

class SinglyLinkedList {
    node* head;
    node* tail;
    int size;

    public:
    SinglyLinkedList(){
        head = new node();
        tail = new node();
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void addFirst(int num){
        node* newnode = new node();
        newnode->elem = num;

        if(size == 0){
            head = newnode;
            tail = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }

        size++;
        return;
    }

    void addLast(int num){
        node* newnode = new node();
        newnode->elem = num;

        if(size == 0){
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }

        size++;
        return;
    }

    int removeFirst(){
        if(size == 0){
            throw logic_error("cannot remove empty list");
        }

        int num = head->elem;
        node* remove = head;
        head = head->next;
        delete remove;
        size--;
        return num;
    }

    int removeLast(){
        if(size == 0){
            throw logic_error("cannot remove empty list");
        }

        int num = tail->elem;
        node* remove = tail;

        if(size == 0){
            head = tail = nullptr;
        } else {
            node *temp = head;
            for(int i = 0; i < size - 2; i++){
                temp = temp->next;
            }
            tail = temp;
            tail->next = nullptr;
        }

        delete remove;
        size--;
        return num;
    }

    int get(int pos){
        if(pos < 0 || pos > size){
            throw logic_error("invalid position");
        }

        node *temp = head;
        int num;
        for(int i = 1; i <= size; i++){
            if(pos == i){
                num = temp->elem;
            }
            temp = temp->next;
        }

        return num;
    }

    void print(){
        node* temp = head;
        while(temp){
            cout << temp->elem << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    SinglyLinkedList *list = new SinglyLinkedList();

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