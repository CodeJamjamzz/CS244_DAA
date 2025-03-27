#include <iostream>
using namespace std;

struct node {
    int value, key;
    bool isDeleted;

    node(int key, int value){
        this->value = value;
        this->key = key;
        isDeleted = false;
    }
};

class HashTable {
    node** table;
    int N, count;

    public:
    HashTable(){
        N = 10;
        count = 0;
        table = (node**) calloc(N,sizeof(node*));
    }

    int compressionFunction(int key){
        return ( (( 59 * key + 17) % 509) % N );
    }

    int insert(int key, int value){
        if(count == N){return -1;}
        int index = compressionFunction(key);
        int start = index;
        while(table[index] != nullptr && !table[index]->isDeleted){
            if (table[index]->key == key) return -1;
            index = (index + 1) % N;
            if (index == start) return -1; // Table is full
        }

        table[index] = new node(key, value);
        count++;
        return value;
    }

    int search(int key){
        if(count == 0){return -1;}
        int index = compressionFunction(key);
        int start = index;
        while(table[index] != nullptr && !table[index]->isDeleted){
            if(!table[index]->isDeleted && table[index]->key == key){
                return table[index]->value;
            }
            index = (index + 1) % N;
            if(index == start){break;}
        }

        return -1;
    }

    int remove(int key){
        int index = compressionFunction(key);
        int start = index;

        while (table[index] != nullptr) {
            if (!table[index]->isDeleted && table[index]->key == key) {
                table[index]->isDeleted = true;
                count--;
                return true;
            }
            index = (index + 1) % N;
            if (index == start) break;
        }
        return false; // Key not found
    }

};

int main(){

}