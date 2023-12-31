// Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

// Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

 

// Example 1:


// Input: n = 7
// Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
// Example 2:

// Input: n = 3
// Output: [[0,0,0]]
 

// Constraints:

// 1 <= n <= 20

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n==1){
            return {new TreeNode(0)};
        }
        vector<TreeNode*>ans;
        for(int i=1; i<n; i+=2){
            vector<TreeNode*>left= allPossibleFBT(i);
            vector<TreeNode*>right= allPossibleFBT(n-i-1);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root = new TreeNode();
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};