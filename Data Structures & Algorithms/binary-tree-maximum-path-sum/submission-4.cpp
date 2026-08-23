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
    int dfs(TreeNode* root,int& result) {
        if ( root == nullptr ) return 0;
        int l = max(0, dfs(root->left, result)); // left max value
        int r = max(0, dfs(root->right, result)); // right max value

        result = max(result, l + root->val + r);
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        int result = root->val;
        return max(result, dfs(root, result));
    }
};
