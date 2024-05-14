#include <iostream>
using namespace std;

//Print Array
void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArr(char arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    printArr(arr, n);
}

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIdx = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        swap(arr[i], arr[minIdx]);
    }

    printArr(arr, n);
}

void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int curr = arr[i];
        int prev = i-1;
        //sorted part loop - backwards
        while(prev >= 0 && arr[prev] > curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }

        //swap
        swap(arr[prev+1], curr);
    }
    
     printArr(arr, n);
}

void countSort(int arr[], int n) {
    int range = INT_MIN;
    for(int i=0; i<n; i++) {
        range = max(range, arr[i]);
    }

    int freqArr[100001];
    for(int i=0; i<n; i++) {
        freqArr[arr[i]]++;
    }

    for(int i=0; i<range; i++) {
        while(freqArr[i] > 0) {
            arr[i] = i;
            freqArr[i]--;
        }
    }

    printArr(arr, n);
}



void sortChars(char arr[], int n) {
    for(int i=1; i<n; i++) {
        char curr = arr[i];
        int prev = i-1;
        
        while(prev >= 0 && arr[prev] < curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }

        swap(arr[prev+1], curr);
    }
    
     printArr(arr, n);
}

int main() {
    int arr[5] = {5, 4, 1, 3, 2};
    //bubbleSort(arr, 5);
    //selectionSort(arr, 5);
    //insertionSort(arr, 5);

    int arr2[8] = {1, 4, 1, 3, 2, 4, 3, 7};
    //countSort(arr2, 8);

    sort(arr2, arr2+8);
    printArr(arr2, 8);

    char ch[] = { 'f', 'b', 'a', 'e', 'c', 'd'};
    sortChars(ch, 6);
    
    return 0;    
}


