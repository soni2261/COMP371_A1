//Sonia Rahal 40211893
//Parker Harris-Bytautas 40207549
#include <iostream>
using namespace std;

int * createArray(int size){
    int* array = new int[size];
    return array;
}

void initializeArray(int* array, int size){
    for (int i = 0; i < size; i++){
        array[i] = i;
    }
}

void printArray(int* array, int size){
    for (int i = 0; i < size; i++){
        cout << array[i];
    }
}

void deleteArray(int* array){
    delete[] array;
}

int main(){
    int size;
    cin >> size;
    cout << "size:" + std::to_string(size) << "\n";
    int *array = createArray(size);
    initializeArray(array, size);
    printArray(array, size);
    deleteArray(array);

    //cout << "array pointer: " << array;
    //delete[] array;
    return 0;
}