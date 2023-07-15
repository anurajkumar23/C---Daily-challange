// You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

// You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

// Return the maximum sum of values that you can receive by attending events.

 

// Example 1:



// Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
// Output: 7
// Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
// Example 2:



// Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
// Output: 10
// Explanation: Choose event 2 for a total value of 10.
// Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
// Example 3:



// Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
// Output: 9
// Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
 

// Constraints:

// 1 <= k <= events.length
// 1 <= k * events.length <= 106
// 1 <= startDayi <= endDayi <= 109
// 1 <= valuei <= 106


class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(vector<vector<int>>& events, int i, int prev, int k) {
        
        if(k == 0 || i == n)
            return 0;
        
        if(t[prev+1][k] != -1) //prev+1 because intially prev is = -1
            return t[prev+1][k];
        
        int start = events[i][0];
        int endt   = events[i][1];
        int value = events[i][2];
        
        
        int take = 0, skip = 0;
        if(prev == -1 || events[prev][1] < events[i][0]) {
            take = value + solve(events, i+1, i, k-1);
        }   
        
        skip = solve(events, i+1, prev, k);
        
        return t[prev+1][k] = max(take, skip);
        
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        auto lambda = [&](auto &a, auto &b) {
            if(a[1]==b[1])  
                return a[0]-b[0];
            
            return a[1]-b[1];
        };
        
        sort(begin(events), end(events));
        
        n = events.size();
        
        t.resize(n+1, vector<int>(k+1, -1));
        
        return solve(events, 0, -1, k);
    }
};