#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

#include "node.hpp"
#include <iostream>
using namespace std;

class LinkedList {
	// IMPLEMENT ME
	node* head;
	node* tail;
    int size;
    
    public:
    LinkedList(){
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    void insert(string key){
        node* newnode = new node(key);
        if(size == 0){
            size++;
            head = newnode;
            tail = newnode;
            return;
        }
        
        tail->next = newnode;
        tail = newnode;
        size++;
        return;
    }
    
    int getSize(){
        return size;
    }
    
    int search(string key){
        node* temp = head;
        while(temp != nullptr){
            if(key == temp->elem){
                return size;
            }
            
            temp = temp->next;
        }
        
        return -1;
    }
    
    int remove(string key){
        node* temp = head;
        if(head->elem == key){
            node* rem = head;
            head = head->next;
            size--;
            return size;
        }
        
        node* prev = nullptr;
        while(temp != nullptr){
            if(temp->elem == key){
                node* rem = temp;
                prev->next = temp->next;
                size--;
                return size;
            }
            
            prev = temp;
            temp = temp->next;
        }
        
        return -1;
    }
    
    void print(){
        node* temp = head;
        while(temp != nullptr){
            cout << temp->elem << "\t";
            temp = temp->next;
        }
    }
	
};

class HTSepChain : public HashTable {
    // IMPLEMENT ME\
    
    LinkedList** table;
    int N;
    
    public:
    HTSepChain(int size){
        table = (LinkedList**) calloc(size , sizeof(LinkedList*));
        N = size;
    }
    
    int hash_code(string key){
        int code = 0;
        int a = 5;
        int length = key.length();
        int ctr = 0;
        for(int i = length - 1; i >= 0; i--){
            code += ( (int) key[ctr]) * pow(a, i);
            ctr++;
        }
        
        return code;
    }
    
    int compress(int code){
        return code % N;
    }
    
    int insert(string key){
        
        int size = 0;
        int index = this->hashfn(key);
        
        
        if(table[index] == nullptr){
            table[index] = new LinkedList();
            table[index]->insert(key);
            size = table[index]->getSize();
        } else {
            if(table[index]->search(key) != -1){
                throw logic_error("Already added key " + key);
            }
            table[index]->insert(key);
            size = table[index]->getSize();
        }
        
        return size;
    }
    
    int search(string key){
        int index = this->hashfn(key);
        if(table[index] == nullptr){
            return -1;
        }
        
        return table[index]->search(key);
        
    }
    int remove(string key){
        int index = this->hashfn(key);
        if(table[index] == nullptr){
            return -1;
        }
        
        if (table[index]->search(key) != -1){
            return table[index]->remove(key);
        } 
        
        return -1;
        
    }
    void print(){
        for(int i = 0; i < N; i++){
            cout << i << "\t";
            if(table[i] != nullptr){
                table[i]->print();
            }
            cout << endl;
        }
        cout << endl;
    }
};

