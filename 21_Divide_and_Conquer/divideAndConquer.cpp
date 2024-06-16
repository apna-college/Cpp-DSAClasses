#include <iostream>
#include <vector>
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int si, int mid, int ei) {
    vector<int> temp;
    int i=si, j=mid+1;

    while(i <= mid && j <= ei) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i++]);
    } 

    while(j <= ei) {
        temp.push_back(arr[j++]);
    }

    //copy back to original
    for(int idx=si, x=0; idx<=ei; idx++) {
        arr[idx] = temp[x++];
    }    
}

void mergeSort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;
    }

    int mid = si + (ei - si)/2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    
    merge(arr, si, mid, ei);
}

int partition(int arr[], int si, int ei) {
    int pivot = arr[ei];
    int i=si-1;

    for(int j=si; j<ei; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[ei]);

    return i;
}

void quickSort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;
    }

    int pivotIdx = partition(arr, si, ei);
    quickSort(arr, si, pivotIdx-1); //left
    quickSort(arr, pivotIdx+1, ei); //right
}

int search(int arr[], int si, int ei, int tar) {
    if(si > ei) {
        return -1;
    }

    int mid = si + (ei - si)/2;

    if(arr[mid] == tar) {
        return mid;
    }

    if(arr[si] <= arr[mid]) { //Line 1
        if(arr[si] <= tar && tar <= arr[mid]) {
            //go left
            return search(arr, si, mid-1, tar);
        } else {
            //go right
            return search(arr, mid+1, ei, tar);
        }
    } else {
        //Line2
        if(tar >= arr[mid] && tar <= arr[ei]) {
            //go right
            return search(arr, mid+1, ei, tar);
        } else {
            //go left
            return search(arr, si, mid-1, tar);
        }
    }
}

int main() {
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = 6;
    
    //mergeSort(arr, 0, n-1);

    quickSort(arr, 0, n-1);
    printArr(arr, n);

    int arr2[7] = {4, 5, 6, 7, 0, 1, 2};
    int tar = 0;
    cout << "idx : " << search(arr2, 0, 6, tar) << endl;
    return 0;    
}


