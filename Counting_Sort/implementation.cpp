#include <iostream>
using namespace std;

int main(){
    int inputarray[] = {1,1,2,2,2,3,7,5,2,5,7};

    cout << inputarray[1] << endl;
    int max = -1;
    for(int i = 0; i < 12; i++){
        if(max < inputarray[i]){
            max = inputarray[i];
        }
    }
    
    cout << max;
    cout << endl;

    int *countarray;
    countarray = (int*) calloc(max, sizeof(int));
    for(int i = 0; i < max; i++){
        int count = 0;
        for(int j = 0; j < 12; j++){
            if(inputarray[j] == i){
                count++;
            }
        }
        countarray[i] = count;
    }

    for(int i = 0; i < max; i++){
        cout << countarray[i] << " ";
    }
}