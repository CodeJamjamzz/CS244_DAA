#include <iostream>
#include <algorithm>
using namespace std;

class ArraySorting {
    int array[12] = {1,5,12,76,12,100,322,56,1,2,3,5};
    
    public:
    int size;
    ArraySorting(){
        size = 12;
    }

    void print(string sort){
        cout << "Printing: " << sort << endl;
        for(int i = 0; i < 12; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }

    int lomutoPartition(int low, int high){
        int pivot = array[low];
        int index = low + 1;

        for(int i = index; i <= high; i++){
            if(array[i] < pivot){
                swap(array[i], array[index]);
                ++index;
            }
        }

        swap(array[low], array[index-1]);
        return index - 1;
    }

    void quickSort(int low, int high){
        if(low < high){
            int lowEnd = lomutoPartition(low, high);
            quickSort(low, lowEnd-1);
            quickSort(lowEnd+1, high);
        }
    }

    void countingSort(){
        int max = -1;
        for(int i = 0; i < size; i++){
            if(array[i] > max){
                max = array[i];
            }
        }
        if(max == -1) return;

        int *countArray = (int*) calloc(max+1, sizeof(int));
        for(int i = 0; i < size; i++){
            countArray[array[i]]++;
        }

        for(int i = 1; i <= max; i++){
            countArray[i] += countArray[i-1];
        }

        int *outputArray = (int*) calloc(size, sizeof(int));
        for(int i = size-1; i >= 0; i--){
            outputArray[countArray[array[i]] - 1] = array[i];
            countArray[array[i]] --;
        }

        cout << "Printing: " << "Counting Sort" << endl;
        for(int i = 0; i < 12; i++){
            cout << outputArray[i] << " ";
        }
        cout << endl;
    }

    void mergeArray(int left, int mid, int right){
        int leftSize = mid - left + 1;
        int rightSize = right - mid;

        int *leftArray = (int*) calloc(leftSize, sizeof(int));
        int *rightArray = (int*) calloc(rightSize, sizeof(int));

        int i;
        for(i = 0; i < leftSize; i++){
            leftArray[i] = array[left+i];
        }

        for(int j = 0; j < rightSize; j++){
            rightArray[j] = array[mid + 1 + j];
        }

        int a = 0, j = 0, k = left;

        while(a < leftSize && j < rightSize){
            if(leftArray[a] < rightArray[j]){
                array[k++] = leftArray[a++]; 
            } else {
                array[k++] = rightArray[j++]; 
            }
        }

        while(a < leftSize){array[k++] = leftArray[a++]; }
        while(j < rightSize){array[k++] = rightArray[j++]; }

    }

    void merge(int left, int right){
        if(left < right){
            int mid = left + (right - left) / 2;

            merge(left, mid);
            merge(mid+1, right);

            mergeArray(left, mid, right);
        }
    }


};

int main(){
    char choice;
    cout << "Enter Sorting Algorithm: ";
    cin >> choice;

    ArraySorting *array;

    switch(choice){
        case 'Q':
            array = new ArraySorting();
            array->quickSort(0,array->size-1);
            array->print("Quick Sort");
            break;
        case 'C':
            array = new ArraySorting();
            array->countingSort();
            break;
        case 'M':
            array = new ArraySorting();
            array->merge(0, array->size-1);
            array->print("Merge Sort");
            break;
    }
}