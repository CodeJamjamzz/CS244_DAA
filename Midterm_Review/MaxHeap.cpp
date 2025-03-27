#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

template <typename T>
class MaxHeap {
    int size;
    int capacity;
    T* array;

    public: 
    MaxHeap(){
        size = 0;
        capacity = 5;
        array = (T*) calloc(capacity, sizeof(T));
    }

    void insert(T value){
        if(size == capacity){
            capacity += ceil(size * 1.5);
            array = (T*) realloc(array, sizeof(T) * capacity);
        }   

        array[size++] = value;

        int index = size - 1, parent = (index - 1) / 2;
        while(index > 0 && array[index] > array[parent]){
            swap(array[index], array[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
        
        return;
    }

    void removeMax(){
        if(size == 0){throw logic_error("Cannot remove empty tree");}
        int root = 0, index = size - 1;

        swap(array[root], array[index]);
        size--;

        if(size <=capacity * (2.0/3.0)){
            capacity -= floor(capacity * 0.25);

            if(capacity <= 5){
                capacity = 5;
            }

            array = (T*) realloc(array, capacity * sizeof(T));
        }

        while(true){
            int left = root * 2 + 1;
            int right = root * 2 + 2;
            int largest = root;

            if(left < size && array[largest] < array[left]){
                largest = left;
            }

            if(right < size && array[largest] < array[right]){
                largest = right;
            }
            
            if(root == largest){
                break;
            }
            
            swap(array[root], array[largest]);
            root = largest;
        }

        return;
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
    
};

int main(){
    MaxHeap<int> *heap = new MaxHeap<int>();

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
                heap->removeMax();
                break;
            case 'p':
                heap->print();
                break;
        }

    } while(option != 'x');
}