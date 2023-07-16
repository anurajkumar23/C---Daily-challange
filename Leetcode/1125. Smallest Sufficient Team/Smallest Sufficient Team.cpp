// In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.

// Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.

// For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
// Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.

// It is guaranteed an answer exists.

 

// Example 1:

// Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
// Output: [0,2]
// Example 2:

// Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
// Output: [1,2]
 

// Constraints:

// 1 <= req_skills.length <= 16
// 1 <= req_skills[i].length <= 16
// req_skills[i] consists of lowercase English letters.
// All the strings of req_skills are unique.
// 1 <= people.length <= 60
// 0 <= people[i].length <= 16
// 1 <= people[i][j].length <= 16
// people[i][j] consists of lowercase English letters.
// All the strings of people[i] are unique.
// Every skill in people[i] is a skill in req_skills.
// It is guaranteed a sufficient team exists.


//Approach-1 (Storing mask in map for memoizing) - Recursion + Memoization
class Solution {
public:
    
    int m, n;
    int target_mask;
    vector<int> result;
    unordered_map<string , int > dp;
    
    void solve(vector<int> &people_skill , int idx , vector<int> &temp, int mask ) {
        
       if(idx == people_skill.size()) {
           if(mask == target_mask) {
               if(result.size() == 0 || result.size() >= temp.size()) {
                   result = temp;
               }
           }
           return;
       }
        
        string s = to_string(idx) + to_string(mask);
        
         if(dp.find(s) != dp.end()) {
           if(dp[s] <= temp.size())
               return ; 
        }
        
        if(result.size() != 0 && temp.size() >= result.size()) 
            return; 
        
        solve(people_skill , idx + 1 , temp , mask ); // no

         if( (mask | people_skill[idx]) != mask) { //Because a person's skill set can be empty. So we won't take them
            temp.push_back(idx);
            solve(people_skill, idx + 1, temp , mask | people_skill[idx]);

            temp.pop_back();
            dp[s] = (temp.size() != 0 ) ? temp.size() : -1;
        }
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();                                                                                          
        m = people.size();
        
        unordered_map<string, int> skills; //skill -> unique number
        for (int i = 0; i < n; ++i)
            skills[req_skills[i]] = i;
        
        // represent each person by a single bitmasked number (k'th bit represents if a person has the k'th skill or not)
        vector<int> people_skill;
        for (auto &v: people) {
            int skill_bit = 0;
            for (string &skill: v)
                skill_bit |= 1 << skills[skill];
            
            people_skill.push_back(skill_bit);
        }
        
        // required set of skills mask (All set to 1s)
        target_mask = pow(2, n) - 1;
        vector<int> temp;
        solve(people_skill, 0, temp, 0);
        return result;
    }
};
