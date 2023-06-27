// You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

// Define a pair (u, v) which consists of one element from the first array and one element from the second array.

// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

// Example 1:

// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// Example 2:

// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [[1,1],[1,1]]
// Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
// Example 3:

// Input: nums1 = [1,2], nums2 = [3], k = 3
// Output: [[1,3],[2,3]]
// Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]

class Solution {
public:

    typedef pair<int, pair<int, int>>p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p ,vector<p>>pq;  //max heap

        int m = nums1.size();
        int n = nums2.size();

        for(int i = 0; i<m; i++){

            for(int j = 0; j<n; j++){
                int sum =nums1[i]+nums2[j];

                if(pq.size() < k){
                    pq.push({sum, {i,j}});
                }else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum, {i,j}});
                }else{
                    break;
                }

            }
        }
        vector<vector<int>> result;
        while(!pq.empty()){

            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            result.push_back({nums1[i],nums2[j]});
        }
        return result;
    }
};