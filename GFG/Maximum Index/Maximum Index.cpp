// Given an array arr[] of n positive integers. The task is to find the maximum of j - i subjected to the constraint of arr[i] <= arr[j].

// Example 1:

// Input:
// n = 9
// arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
// Output: 
// 6
// Explanation: 
// In the given array arr[1] < arr[7]  satisfying 
// the required condition (arr[i] <= arr[j])  thus 
// giving the maximum difference of j - i which is
// 6(7-1).
// Example 2:

// Input:
// N = 2
// arr[] = {18, 17}
// Output: 
// 0
// Explanation: 
// We can either take i and j as 0 and 0 
// or we cantake 1 and 1 both give the same result 0.
// Your Task:
// Complete the function maxIndexDiff() which takes array arr and size n, as input parameters and returns an integer representing the answer. You don't to print answer or take inputs. 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 106
// 0 ≤ Arr[i] ≤ 109

int maxIndexDiff(int arr[], int n) {
        // code 
        int *left = new int[n];
        int *right = new int[n];
        
        left[0] = arr[0];
        int maxi = -1;
        for(int i = 1; i<n;i++ ){
            left[i] = min(arr[i] , left[i-1]);
        }
        right[n-1] = arr[n-1];
        for(int i = n-2; i >=0 ; i--) {
            right[i] =  max(arr[i] , right[i+1]);
        }
        
        int i = 0 , j = 0;
        
        while(j < n && i < n ) {
            if(left[i] <= right[j]) {
                maxi = max(maxi , j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return maxi;
    }