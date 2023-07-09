// You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

// Example 1:

// Input:
// N = 5
// arr[] = {1,2,3,4,5}
// Output: 6
// Explanation: Smallest positive missing 
// number is 6.
// Example 2:

// Input:
// N = 5
// arr[] = {0,-10,1,3,-20}
// Output: 2
// Explanation: Smallest positive missing 
// number is 2.
// Your Task:
// The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 106
// -106 <= arr[i] <= 106

 int missingNumber(int arr[], int n) 
    { 
        // Your code here
        sort(arr,arr+n);
        long smallest =1;
        for(int i =0; i<n; i++){
            if(arr[i]==smallest){    //if smallest is equal to arr[i]
            smallest++;              //then smallest increase and again check it is equal to arr[i],if not then return smallest.
           }
        }
        return smallest;
    } 