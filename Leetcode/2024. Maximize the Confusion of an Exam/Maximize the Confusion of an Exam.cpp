// A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

// You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

// Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
// Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

 

// Example 1:

// Input: answerKey = "TTFF", k = 2
// Output: 4
// Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
// There are four consecutive 'T's.
// Example 2:

// Input: answerKey = "TFFT", k = 1
// Output: 3
// Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
// Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
// In both cases, there are three consecutive 'F's.
// Example 3:

// Input: answerKey = "TTFTTFTT", k = 1
// Output: 5
// Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
// Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
// In both cases, there are five consecutive 'T's.
 

// Constraints:

// n == answerKey.length
// 1 <= n <= 5 * 104
// answerKey[i] is either 'T' or 'F'
// 1 <= k <= n


//Approach-1 (Simple Brute Force) - O(n * 2^n)
class Solution {
public:
    int ans = 0;
    int n;
    
    void findMax(string answerKey) {
        int length = 0;
        
        int i = 0;

        while(i < n) {
            
            if(answerKey[i] == 'T') {
                length = 1;
                i++;
                while(i < n && answerKey[i] == 'T') {
                    length++;
                    i++;
                }
                ans = max(ans, length);
            } else {
                length = 1;
                i++;
                while(i < n && answerKey[i] == 'F') {
                    length++;
                    i++;
                }
                ans = max(ans, length);
            }
            
        }
    }
    
    void solve(int idx, string &answerKey, int k) {
        
        findMax(answerKey);
        
        if(idx >= n || k <= 0) {
            return;
        }
        
        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T'; //Flipped
        
        solve(idx+1, answerKey, k-1);
        
        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T'; //Flipped back
        solve(idx+1, answerKey, k);
        
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        n = answerKey.length();
        
        solve(0, answerKey, k);
        
        return ans;
    }
};


//Approach-2 (Using a Sliding Window twice)
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int result = 0;
        //First pass for flipping 'F' -> 'T'
        
        int i = 0, j = 0;
        int countF = 0;
        while(j < n) {
            if(answerKey[j] == 'F')
                countF++;
            
            while(countF > k) {
                if(answerKey[i] == 'F')
                    countF--;
                i++;
            }
            
            result = max(result, j-i+1);
            
            j++;
        }
        
        i = 0, j = 0;
        int countT = 0;
        while(j < n) {
            if(answerKey[j] == 'T')
                countT++;
            
            while(countT > k) {
                if(answerKey[i] == 'T')
                    countT--;
                i++;
            }
            
            result = max(result, j-i+1);
            j++;
        }
        
        
        return result;
    }
    
};

//Approach-3 (Using One Pass Sliding Window)
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int result = k;
        
        unordered_map<char, int> mp;

        int i = 0;
        for (int j = 0; j < answerKey.length(); j++) {

            mp[answerKey[j]]++;
            
            while (min(mp['T'], mp['F']) > k) {
                mp[answerKey[i]]--;
                i++;
            }
            
            result = max(result, j - i + 1);
        }
        
        return result;
    }
};