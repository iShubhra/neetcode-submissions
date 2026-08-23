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
    TreeNode* constructTree(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
        if ( pl > pr ) return nullptr;
        TreeNode* root = new TreeNode(preorder[pl]);
        int pos = il;
        while ( preorder[pl] != inorder[pos] ) pos++;

        int leftCount = pos - il;
        root->left = constructTree(preorder, pl + 1 , pl + leftCount, inorder, il, pos - 1);
        root->right = constructTree(preorder, pl + leftCount + 1, pr, inorder, pos + 1, ir);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return constructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
