// You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

// You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.

// Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.

 

// Example 1:

// Input: rods = [1,2,3,6]
// Output: 6
// Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.
// Example 2:

// Input: rods = [1,2,3,4,5,6]
// Output: 10
// Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.
// Example 3:

// Input: rods = [1,2]
// Output: 0
// Explanation: The billboard cannot be supported, so we return 0.


class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
       int sum = 0;
        for (int rod : rods) {
            sum += rod;
        }

        int dp[sum + 1];
        dp[0] = 0;

        // Initialize all other elements in dp[] to -1
        for (int i = 1; i <= sum; i++) {
            dp[i] = -1;
        }

        for (int rod : rods) {
            int dpCopy[sum + 1];
            // Copy the current state of dp[] to dpCopy[]
            copy(dp, dp + (sum + 1), dpCopy);

            for (int i = 0; i <= sum - rod; i++) {
                if (dpCopy[i] < 0) continue;

                // Case 1: Place the current rod on the same height billboard
                dp[i + rod] = max(dp[i + rod], dpCopy[i]);

                // Case 2: Place the current rod on the taller billboard
                // Calculate the absolute difference between current height and rod length
                dp[abs(i - rod)] = max(dp[abs(i - rod)], dpCopy[i] + min(i, rod));
            }
        }

        // Return the maximum height of the billboard stored at dp[0]
        return dp[0];
    }
};