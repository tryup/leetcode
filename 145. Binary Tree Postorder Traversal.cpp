/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> _vec;
        _postorderTraversal(root,_vec);
        return _vec;
    }

private:
    void _postorderTraversal(TreeNode* root, vector<int>& vec){
        if( nullptr == root ) {
            return;
        }
        _postorderTraversal(root->left,vec);
        _postorderTraversal(root->right,vec);
        vec.push_back(root->val);
    }
};