// Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

// Example 1:

// Input: n = 3, r = 2
// Output: 3
// Explaination: 3C2 = 3. 
// Example 2:

// Input: n = 2, r = 4
// Output: 0
// Explaination: r is greater than n.


class Solution{
public:
    int nCr(int n, int r){
        // code here
        if(n<r) return 0;
        if((n-r)<r) r= n-r;  
        int MOD = 1000000007;
        
        int dp[r+1]; //1 available in every col 
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;  //starting from 1
        for(int i=1; i<=n; i++){
            for(int j= min(r,i); j>0; j--){
                dp[j] = (dp[j] + dp[j-1])%MOD;
            }
        }
        return dp[r];
    }
}