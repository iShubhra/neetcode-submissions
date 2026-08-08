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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if ( root == nullptr ) return result;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> arr;
        int count = 0;
        int size = 1;
        while ( !q.empty() ) {
            TreeNode* node = q.front(); q.pop();
            if ( node->left != NULL ) q.push(node->left);
            if ( node->right != NULL ) q.push(node->right);
            count++;
            arr.push_back(node->val);
            if ( count == size ) {
                result.push_back(arr);
                arr.clear();
                count = 0;
                size = q.size();
            }
        }

        return result;
    }
};
