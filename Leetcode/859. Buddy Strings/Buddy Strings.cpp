// Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

// Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

// For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 

// Example 1:

// Input: s = "ab", goal = "ba"
// Output: true
// Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
// Example 2:

// Input: s = "ab", goal = "ab"
// Output: false
// Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
// Example 3:

// Input: s = "aa", goal = "aa"
// Output: true
// Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
 

// Constraints:

// 1 <= s.length, goal.length <= 2 * 104
// s and goal consist of lowercase letters.


class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        int diff1 = -1, diff2 = -1;
        unordered_set<char> A_letters;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                if (diff1 == -1)
                    diff1 = i;
                else if (diff2 == -1)
                    diff2 = i;
                else
                    return false; // More than 2 different places between A & B
            }
            A_letters.insert(A[i]);
        }
        if (diff1 != -1 && diff2 != -1) // There are 2 different places
            return A[diff1] == B[diff2] && A[diff2] == B[diff1]; 
        if (diff1 != -1) // Only have 1 different place
            return false;
        return A_letters.size() < A.size(); // No different between A & B, check if A contains at least 1 duplicate letters.
    }
};