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
    int maxDepth(TreeNode* root, int count){
        if(!root) return 0;
        count += max(maxDepth(root->left, count), maxDepth(root->right, count)) + 1;
        return count;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int troot = (maxDepth(root->left, 0) + maxDepth(root->right, 0));
        int tleft = diameterOfBinaryTree(root->left);
        int tright = diameterOfBinaryTree(root->right);
        return max(troot, max(tleft, tright));
    }
};