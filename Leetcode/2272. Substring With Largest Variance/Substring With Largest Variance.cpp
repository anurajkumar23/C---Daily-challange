// The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.

// Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: s = "aababbb"
// Output: 3
// Explanation:
// All possible variances along with their respective substrings are listed below:
// - Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
// - Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
// - Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
// - Variance 3 for substring "babbb".
// Since the largest possible variance is 3, we return it.
// Example 2:

// Input: s = "abcde"
// Output: 0
// Explanation:
// No letter occurs more than once in s, so the variance of every substring is 0.
 

// Constraints:

// 1 <= s.length <= 104
// s consists of lowercase English letters.



//Approach-1 (Brute Force)
/*
  Find all substrings
  Find max freq and min freq of chars
  result = max(result, max_freq - min_freq)
*/


//Approach-2 (26*26*n)
class Solution {
public:
    int largestVariance(string s) {
        vector<int> count(26, 0);
        
        for(char &ch : s) {
            count[ch-'a']++;
        }
        
        int result = 0;

        for (char first = 'a'; first <= 'z'; ++first) {

            for (char second = 'a'; second <= 'z'; ++second) {

                if (count[first-'a'] == 0 || count[second-'a'] == 0) 
                    continue;

                int firstCount = 0;
                int secondCount = 0;
                bool pastLowFreq = false;

                for (const char& ch : s) {
                    if (ch == first) ++firstCount;
                    if (ch == second) ++secondCount;

                    if (secondCount > 0) {
                        result = max(result, firstCount - secondCount);
                    } else {
                        if (pastLowFreq) {
                            result = max(result, firstCount - 1);
                        }
                    } 

                    if (secondCount > firstCount) {
                        secondCount = 0;
                        firstCount = 0;
                        pastLowFreq = true;
                    }
                }
            }
        }
        return result;
    }
};