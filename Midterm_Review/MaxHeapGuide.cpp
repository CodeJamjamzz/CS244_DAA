#include <iostream>
#include <excpt.h>
#include <cmath>
using namespace std;

class Min_Heap {
    int *array;
    int size;
    int capacity;

    public:
    
    Min_Heap(): size(0), capacity(5){
        array = (int*) calloc(capacity, sizeof(int)); 
    }

    void swap(int *arrayInput, int child, int parent){
        int temp = arrayInput[child];
        arrayInput[child] = arrayInput[parent];
        arrayInput[parent] = temp;
        return;
    }

    void insert(int input){

        if(size == capacity){
            capacity += ceil(size * 1.5);
            array = (int*) realloc(array, sizeof(int) * capacity);
        }   

        array[size++] = input;

        int index = size - 1, parent = (index - 1) / 2;
        while(index > 0 && array[index] < array[parent]){
            swap(array, index, parent);
            index = parent;
            parent = (index - 1) / 2;
        }
    } 

    void removeMin(){
        if(size <= 0) throw logic_error("The tree is empty");
        int root = 0, index = size - 1;
        swap(array, root, index);

        free(array + index);
        size--;

        if(size <= capacity * 2.0/3.0){
            capacity -= floor(capacity * 0.25);

            if(capacity < 5){
                capacity = 5;
            } else {
                array = (int*) realloc(array, sizeof(int) * capacity);
            }
        }
        
        while(true){
            int left = root * 2 + 1;
            int right = root * 2 + 2;
            int smallest = root;

            if(left < size && array[smallest] > array[left]){
                smallest = left;
            }

            if(right < size && array[smallest] > array[right]){
                smallest = right;
            }

            if(array[smallest] < array[root]){
                swap(array, smallest, root);
                root = smallest;
            } else {
                break;
            }
        }

    }

    int getRoot(){
        return array[0];
    }

    void print(){
        cout << "Min Heap:" << endl;
        for(int i = 0; i < size; i++){
            cout << array[i] << " ";
        }

        cout << endl;
    }


};

int main(){
    Min_Heap *heap = new Min_Heap();

    char option;
    int input;

    do{
        cout << "Enter option: ";
        cin >> option;

        switch(option){
            case 'a':
                cout << "Enter number: ";
                cin >> input;

                heap->insert(input);
                break;
            case 'r':
                heap->removeMin();
                break;
            case 'p':
                heap->print();
                break;
        }

    } while(option != 'x');
}

