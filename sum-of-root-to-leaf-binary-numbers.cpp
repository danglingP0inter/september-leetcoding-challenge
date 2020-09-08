/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //Do preorder
    int sum(TreeNode* root, int ans) {
        if(!root) return 0;
        ans = (ans<<1) + root->val;
        
        if(!root->left && !root->right) return ans;
        return sum(root->left, ans) + sum(root->right, ans);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return sum(root, 0);
    }
};
