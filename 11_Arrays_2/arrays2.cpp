#include <iostream>
using namespace std;

//max sum subarray (brute force - O(N^3))
int maxSumSubarray(int *arr, int n) {
    int maxSum = INT_MIN; 
    for(int start=0; start<n; start++) {
        for(int end=start; end<n; end++) {
            int sum = 0;
            for(int i=start; i<=end; i++) {
                sum += arr[i];
            }
            maxSum = max(sum, maxSum);
        }
    }

    cout << maxSum << "\n";
    return maxSum;
}

//max sum subarray - O(N^2)
int maxSumSubarray2(int *arr, int n) {
    int maxSum = INT_MIN; 
    for(int start=0; start<n; start++) {
        int sum = 0;
        for(int i=start; i<n; i++) {
            sum += arr[i];
            maxSum = max(sum, maxSum);
        }
    }

    cout << maxSum << "\n";
    return maxSum;
}

//max sum subarray - Kadane's - O(N)
int maxSumSubarray3(int *arr, int n) {
    int currSum = 0;
    int maxSum = INT_MIN; 
    
    for(int i=0; i<n; i++) {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        
        if(currSum < 0) {
            currSum = 0;
        }
    }

    cout << maxSum << "\n";
    return maxSum;
}

//Trapping Rainwater
int trap(int *heights, int n) {
    int maxLeft[100000] = {0};
    int maxRight[100000] = {0};

    int maxTillNow = heights[0];
    for(int i=1; i<n; i++) {
        maxLeft[i] = max(maxTillNow, heights[i-1]);
        maxTillNow = max(maxTillNow, heights[i]);
    }

    maxRight[n-1] = 0;
    maxTillNow = heights[n-1];
    for(int i=n-2; i>=0; i--) {
        maxRight[i] = max(maxTillNow, heights[i+1]);
        maxTillNow = max(maxTillNow, heights[i]);
    }

    int water = 0;
    for(int i=0; i<n; i++) {
        int ht = min(maxLeft[i], maxRight[i]) - heights[i];
        if(ht > 0) {
            water += ht;
        }
    }

    cout << "water trapped = " << water << "\n";
    return water;
}

//Buy & Sell Stocks
int maxProfit(int *prices, int n) {
    int bestBuy[100000] = {0};
    bestBuy[0] = INT_MAX;

    for(int i=1; i<n; i++) {
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
    }

    int maxProfit = 0;
    for(int i=1; i<n; i++) {
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }

    cout << "max profit = " << maxProfit << "\n";
    return maxProfit;
}

int main() {
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    maxSumSubarray(arr, n);
    maxSumSubarray2(arr, n);
    maxSumSubarray3(arr, n);

    int arr2[] = {-1, -2, -3};
    maxSumSubarray3(arr2, 3);

    int heights[] = {4, 2, 0, 6, 3, 2, 5};
    trap(heights, 7);

    int prices[] = {7,1,5,3,6,4};
    maxProfit(prices, 6);
    return 0;    
}


