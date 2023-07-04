// Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.

// Example 1:

// Input : 
// n = 4, k = 10
// a[] = {1, 2, 3, 4}
// Output : 
// 7
// Explanation:
// The contiguous subarrays are {1}, {2}, {3}, {4} 
// {1, 2}, {1, 2, 3} and {2, 3} whose count is 7.
// Example 2:

// Input:
// n = 7 , k = 100
// a[] = {1, 9, 2, 8, 6, 4, 3}
// Output:
// 16
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function countSubArrayProductLessThanK() which takes the array a[], its size n and an integer k as inputs and returns the count of required subarrays.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)


 public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans=0,r=0,l=0;
        long long p=1;
        while(r<n){
            p*=a[r];
            while(p>=k){
                p/=a[l];
                l++;
            }
            if(l<=r){
                int len=r-l+1;
                ans+=len;
            }
            r++;
        }
        return ans;
    }