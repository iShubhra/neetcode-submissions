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
    TreeNode* res;
    bool isSameTree(TreeNode* l, TreeNode* r, TreeNode* p, TreeNode* q) {
        if ( !l || !r ) return false;
        if ( l == p && r && r == q ) return true;
        if ( l == p && r != q ) {
            return isSameTree(l, r->left ,p, q) || isSameTree(l, r->right ,p, q);
        }

        if ( l != p && r == q  ) {
            return isSameTree(l->left, r ,p, q) || isSameTree(l->right, r ,p, q); 
        }

        return isSameTree(l->left, r->left, p, q) || isSameTree(l->right, r->right, p, q) || isSameTree(l->left, r->right, p, q) || isSameTree(l->right, r->left, p, q);
    }

    void same(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( !root ) return;
        if ( isSameTree(root, root, p, q) ) {
            res = root;
            same(root->left, p, q);
            same(root->right, p, q);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        res = root;
        same(root,p,q);
        return res;
    }
};
