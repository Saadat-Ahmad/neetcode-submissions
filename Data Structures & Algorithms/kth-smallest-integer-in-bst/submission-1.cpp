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
private: 
    int l;
    int ans;
public:
    void kthSmallestHelper(TreeNode* root){
        if(!root) return;
        kthSmallestHelper(root->left);
        if(l==0) return;   
        ans = root->val;
        l--;
        kthSmallestHelper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        this->l = k;
        kthSmallestHelper(root);
        return this->ans;
    }
};
