#include <iostream>
using namespace std;

struct node {
    int key, value;
    node* next;

    public:
    node(int key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
    }

    int getValue(){
        return value;
    }

    int getKey(){
        return key;
    }

};

class LinkedList {
    int size;

    public:
    node* head;
    node* tail;

    LinkedList(){
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void insert(int key, int value){
        node* newnode = new node(key, value);
        if(size == 0){
            size++;
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
        return;
    }

    int search(int key){
        node* temp = head;
        while(temp != nullptr){
            if(temp->getKey() == key){
                return temp->getValue();
            }

            temp = temp->next;
        }

        return -1;
    }

    int getHead(){
        if(head == nullptr){return -1;}
        return head->getValue();
    }

    int getSize(){
        return size;
    }

    int remove(int key){
        if(size == 0){return -1;}

        node* temp = head;
        node* prev = nullptr;
        if(head->key == key){
            node* rem = head;
            int removed = head->getValue();
            head = head->next;
            delete(rem);
            size--;
            return removed;
        }

        while(temp != nullptr){
            if(temp->key == key){
                node* rem = temp;
                int removed = temp->getValue();
                prev->next = temp->next;
                delete(rem);
                size--;
                return removed;
            }

            prev = temp;
            temp = temp->next;
        }
        
        return -1;
    }

};

class HashTable {
    int size;
    LinkedList** array;

    int hashFunction(int key){
        return key % size;
    }

    public:
    HashTable(){
        size = 20;
        array = (LinkedList**) malloc(size * sizeof(LinkedList*));
    }

    void insert(int key, int value){
        if(size >= 20){
            throw logic_error("The Hashtable is already full.");
        }

        int index = hashFunction(key);
        if(array[index] == nullptr){
            array[index] = new LinkedList();
            array[index]->insert(key, value);
        } else {
            array[index]->insert(key, value);
        }
    }

    int getSize(){
        return size;
    }

    int searchValue(int key){
        if(size == 0){return -1;}
        int index = hashFunction(key);
        if(array[index]->getSize() > 1){
            if(array[index]->search(key) != -1){
                return array[index]->search(key);
            } else {
                return -1;
            }
        } else {
            if(array[index]->getHead() != -1){
                return array[index]->getHead();
            } else {
                return -1;
            }
        }
    }

    int remove(int key){
        if(size == 0){return -1;}
        int index = hashFunction(key);

        if(array[index]->getSize() > 1){
            array[index]->remove(key);
        } else {
            delete array[index];
            array[index] = nullptr;
        }
    }

};