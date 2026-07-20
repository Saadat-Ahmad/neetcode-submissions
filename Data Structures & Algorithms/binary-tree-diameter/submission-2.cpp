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
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int troot = dfs(root->left) + dfs(root->right);
        int tleft = diameterOfBinaryTree(root->left);
        int tright = diameterOfBinaryTree(root->right);
        return max(troot, max(tleft, tright));
    }
};