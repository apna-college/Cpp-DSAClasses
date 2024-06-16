#include <iostream>
#include <vector>
using namespace std;

// Pair Sum
vector<int> twoSum(vector<int>& nums, int target) {
        int st = 0, end = nums.size()-1;
        vector<int> ans;

        while(st < end) {
            int sum = nums[st] + nums[end];
            if(sum == target) {
                ans.push_back(st+1);
                ans.push_back(end+1);
                break;
            } else if(sum > target) {
                end--;
            } else {
                st++;
            }
        }

        return ans;
}

int main() {
    //Dynamic Allocation & Deallocation
    //Example - 1
    int *ptr = new int;
    *ptr = 100;
    cout << *ptr << endl;
    delete ptr;
    
    //1D Dynamic Array
    int size;
    cout << "enter size of array : ";
    cin >> size;
    int *arr = new int[size];

    for(int i=0; i<size; i++) {
        arr[i] = i+1;
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    //2D Dynamic Array
    int rows, cols;
    cout << "enter rows : ";
    cin >> rows;
    cout << "enter cols : ";
    cin >> cols;

    int **matrix = new int*[rows];
    for(int i=0; i<rows; i++) {
        matrix[i] = new int[cols];
    }

    int x = 1;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //vectors
    vector<int> vec1;

    vector<int> vec2 = {1, 2, 3, 4};

    vector<int> vec3(5, -1);

    vector<int> vec = {1, 2, 3, 4};
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;

    //print elements
    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    vec.push_back(5);
    cout << vec.capacity() << endl;

    //2D Vector
    vector<vector<int>> matrix = {{1}, {2, 3}, {4, 5, 6}};

    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;    
}


