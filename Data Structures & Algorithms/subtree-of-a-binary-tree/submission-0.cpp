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
    bool helperSubtree(TreeNode* root, TreeNode* subRoot){
        if(!subRoot && !root) return true;
        if(!subRoot || !root) return false;
        if(subRoot->val != root->val) return false;
        return helperSubtree(root->left, subRoot->left) && helperSubtree(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        if(root-> val != subRoot->val){
            bool l = isSubtree(root->left, subRoot);
            bool r = isSubtree(root->right, subRoot);
            return l || r;
        } else {
            if(helperSubtree(root, subRoot)) return true; 
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};