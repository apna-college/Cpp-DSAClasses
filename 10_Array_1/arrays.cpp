#include <iostream>
using namespace std;

void printArr(int *arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
}

int linearSearch(int *arr, int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }

    return -1;
}

void findLargest(int *arr, int n) {
    int max;
    for(int i=0; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "max = " << max << endl;
}

//copy & paste method
void reverseArr1(int *arr, int n) {
    int newArr[n];
    for(int i=0; i<n; i++) {
        newArr[i] = arr[n-i-1];
    }

    for(int i=0; i<n; i++) {
        arr[i] = newArr[i];
    }

    printArr(arr, n);
}

//2 pointer method
void reverseArr2(int *arr, int n) {
    int start = 0, end = n-1;
    
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    printArr(arr, n);
}

//Binary Search
int binSearch(int *arr, int n, int key) {
    int start = 0, end = n-1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(key == arr[mid]) {
            return mid;
        } else if(key > arr[mid]) {
            //search in 2nd half
            start = mid + 1;
        } else {
            //search in 1st half
            end = mid - 1;
        }
    }

    return -1;
}

//Print all Subarrays of an Array
void printSubarrays(int *arr, int n) {
    for(int start=0; start<n; start++) {
        for(int end=start; end<n; end++) {

            for(int i=start; i<=end; i++) {
                cout << arr[i] << ",";
            }
            cout << endl;
        }
    }
}


int main() {
    //Creating an array
    int marks[5];
    cout << marks[0] << ", " << marks[4] << endl;

    int ages[50] = {24, 48, 64};
    cout << ages[0] << "," << ages[49]<< endl;

    float heights[] = {5.5, 4.9, 6.2};
    cout << heights[0] << endl;

    //Size of array
    int a[5];
    int n = sizeof(a) / sizeof(int);
    cout << "size = " << n << endl;

    //Input & Output Array
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << ",";
    }
    cout << "\n";

    int arr[] = {1, 2, 3, 4, 5};
    printArr(arr, 5);

    cout << linearSearch(arr, 5, 3) << endl;

    reverseArr1(arr, 5);
    reverseArr2(arr, 5);

    cout << binSearch(arr, 5, 3) << endl;

    printSubarrays(arr, 5);
    return 0;
}


