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
    int result;
    int dfs(TreeNode* root) {
        if ( root == nullptr ) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);

        result = max(root->val, max(result, l + root->val + r));
        result = max(result, root->val + max(l, r));
        
        return max(root->val, root->val + max(l, r));
    }

    int maxPathSum(TreeNode* root) {
        result = root->val;
        return max(result, dfs(root));
    }
};
