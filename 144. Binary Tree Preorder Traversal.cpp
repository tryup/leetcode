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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> _vec;
        _preorderTraversal(root,_vec);
        return _vec;
    }

private:
    void _preorderTraversal(TreeNode* root, vector<int>& vec){
        if( nullptr == root ) {
            return;
        }
        vec.push_back(root->val);
        _preorderTraversal(root->left,vec);
        _preorderTraversal(root->right,vec);

    }
};