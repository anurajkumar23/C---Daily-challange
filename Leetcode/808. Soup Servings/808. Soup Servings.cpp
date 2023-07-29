// There are two types of soup: type A and type B. Initially, we have n ml of each type of soup. There are four kinds of operations:

// Serve 100 ml of soup A and 0 ml of soup B,
// Serve 75 ml of soup A and 25 ml of soup B,
// Serve 50 ml of soup A and 50 ml of soup B, and
// Serve 25 ml of soup A and 75 ml of soup B.
// When we serve some soup, we give it to someone, and we no longer have it. Each turn, we will choose from the four operations with an equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as possible. We stop once we no longer have some quantity of both types of soup.

// Note that we do not have an operation where all 100 ml's of soup B are used first.

// Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:

// Input: n = 50
// Output: 0.62500
// Explanation: If we choose the first two operations, A will become empty first.
// For the third operation, A and B will become empty at the same time.
// For the fourth operation, B will become empty first.
// So the total probability of A becoming empty first plus half the probability that A and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.
// Example 2:

// Input: n = 100
// Output: 0.71875
 

// Constraints:

// 0 <= n <= 109


class Solution {
public:
    vector<int>optionA={100,75,50,25};
    vector<int>optionB={0,25,50,75};

    double solve(int a, int b, vector<vector<double>> &dp){
        if(a==0&&b==0)
        return 0.5;//half the probability that A and B become empty at the same time
        if(a==0)
        return 1;
        if(b==0) return 0; 
        
        if(dp[a][b] != -1) return dp[a][b];
        
        double ans=0;
        for(int k=0;k<4;k++){
            int rema=a-optionA[k];
            int remb=b-optionB[k];
            ans =ans+ 0.25*solve(max(0,rema), max(0,remb), dp);
        }
        
        return dp[a][b]=ans;
    }
    
    double soupServings(int n) {
        if(n>=4800) return 1;//since we want to calculate the probability of a .so we can see that the a will become 0 at fast rate as we increase n because a is decresing at more faster rate and at sume point probaility reaches 1 for soup A will be empty first .
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
        return solve(n,n,dp);
    }
};