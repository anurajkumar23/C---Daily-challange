// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
// Example 2:

// Input: root = [1], target = 1, k = 3
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [1, 500].
// 0 <= Node.val <= 500
// All the values Node.val are unique.
// target is the value of one of the nodes in the tree.
// 0 <= k <= 1000
// Accepted
// 332.1K
// Submissions
// 526.7K
// Acceptance Rate
// 63.1%


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int helper(TreeNode *root, TreeNode *target, vector<pair<TreeNode *, pair<int, int> > > &ans)
    {
        if(root == NULL) return -1;
        if(root->val == target->val) {
            ans.push_back({root, {0,2}});
            return 0;
        }
        int left = helper(root->left, target, ans);
        int right = helper(root->right, target, ans);
        if(left != -1) {
             ans.push_back({root, {left+1, 0} });
             return left+1;
        }
        if(right != -1) {
            ans.push_back({root, {right+1, 1} });
             return right+1;
        }
        return -1;
    }
    void helper(TreeNode *root, int level, vector<int> &ans)
    {
        if(root == NULL) return;
        if(level == 0) {
            ans.push_back(root->val);
            return;
        }
        helper(root->left, level-1, ans);
        helper(root->right, level-1, ans);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<pair<TreeNode *, pair<int, int> > > path;
        helper(root, target, path);
        vector<int> ans;
        for(auto a : path)
        {
            TreeNode *curr = a.first;
            int level = a.second.first;
            int temp = a.second.second;
            if(level == k)
                ans.push_back(curr->val);
            else if(level < k)
            {
                if(temp == 1) {
                     helper(curr->left,k-level-1,ans);
                }
                else if(temp == 0) {
                     helper(curr->right,k-level-1,ans);
                }
                else if(temp == 2) {
                    helper(curr->left,k-1,ans);
                    helper(curr->right,k-1,ans);
                }
            }
        }
        return ans;
    }
};