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
        int pos = -1;
        for ( int i = il; i <= ir; i++ ){
            if ( preorder[pl] == inorder[i] ){
                pos = i;
                break;
            }
        }
        
        int left = pl + 1;
        int mid = pl + pos - 1 - il + 1;

        root->left = constructTree(preorder, left , mid ,inorder, il, pos - 1);
        root->right = constructTree(preorder, mid + 1 , pr, inorder, pos + 1, ir);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return constructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
