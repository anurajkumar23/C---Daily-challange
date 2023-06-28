// You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

// Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

// If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

// Example 1:



// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
// Output: 0.25000
// Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
// Example 2:



// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
// Output: 0.30000
// Example 3:



// Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
// Output: 0.00000
// Explanation: There is no path between 0 and 2.
 

// Constraints:

// 2 <= n <= 10^4
// 0 <= start, end < n
// start != end


class Solution {
public:
    
    typedef pair<double, int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;
        vector<double> result(n, 0);
        
        for(int i=0;i<edges.size();i++)
        {
            int u       = edges[i][0];
            int v       = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        priority_queue<P> pq; //max heap because we need maximum probability

		result[start] = 1;
		pq.push({1.0, start});

		while(!pq.empty()) {

		    int curnode    = pq.top().second;
            double curProb = pq.top().first;
            pq.pop();

            for(auto &child : adj[curnode])
            {
                if(result[child.first] < curProb*child.second) //we want maximum this time
                {
                    result[child.first] = curProb*child.second;
                    pq.push({result[child.first], child.first});
                }
            }

		}

		return result[end];

    }
};