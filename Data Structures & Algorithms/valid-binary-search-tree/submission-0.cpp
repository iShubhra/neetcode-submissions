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
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }

    bool isValid(TreeNode* root, int low, int high) {
        if ( root == nullptr ) return true;
        if ( root->val <= low || root->val >= high )  return false;
        return isValid(root->left, low, root->val) && isValid(root->right,root->val, high);
    }
};
