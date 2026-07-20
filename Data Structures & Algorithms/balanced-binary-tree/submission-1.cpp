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
    int depth(TreeNode* root, int n){
        if(!root) return 0;
        n = max(depth(root->left, n+1), depth(root->right, n+1)) + 1;
        return n;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int l = depth(root->left, 0);
        int r = depth(root->right, 0);
        return abs(l-r) < 2 && isBalanced(root->right) && isBalanced(root->left);
    }
    
};