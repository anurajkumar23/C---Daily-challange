// Given a String, find the longest palindromic subsequence.

// Example 1:

// Input:
// S = "bbabcbcab"
// Output: 7
// Explanation: Subsequence "babcbab" is the
// longest subsequence which is also a palindrome.
// Example 2:

// Input: 
// S = "abcd"
// Output: 1
// Explanation: "a", "b", "c" and "d" are
// palindromic and all have a length 1.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestPalinSubseq() which takes the string S as input and returns an integer denoting the length of the longest palindromic subsequence of S.

// Expected Time Complexity: O(|S|*|S|).
// Expected Auxiliary Space: O(|S|*|S|).

// Constraints:
// 1 ≤ |S| ≤ 1000

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
         int n=A.length();
        int dp[n][n];
        for(int i=0; i<n; i++)
        dp[i][i]=1;
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<n-i+1; j++)
            {
                int k=j+i-1;
                if(A[j]==A[k] && i==2)
                dp[j][k]=2;
                else if(A[k]==A[j])
                dp[j][k]=2+dp[j+1][k-1];
                else
                dp[j][k]=max(dp[j+1][k], dp[j][k-1]);
                
            }
        }
        return dp[0][n-1];
    }
}