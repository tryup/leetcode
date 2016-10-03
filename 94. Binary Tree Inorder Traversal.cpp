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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> _vec;
        _inorderTraversal(root,_vec);
        return _vec;
    }

private:

    void _inorderTraversal(TreeNode* root, vector<int>& vec){
        if( nullptr == root ) {
            return;
        }
        _inorderTraversal(root->left,vec);
        vec.push_back(root->val);
        _inorderTraversal(root->right,vec);
    }
};
//中序遍历递归实现，题目中要求Note: Recursive solution is trivial, could you do it iteratively?
//非递归版本，需要模拟栈
#include <stack>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> _vec;
        _inorderTraversal(root,_vec);
        return _vec;
    }

private:

    void _inorderTraversal(TreeNode* root, vector<int>& vec){
        stack<TreeNode*> _stack;
        _stack.push(root);

        while(!_stack.empty())
        {
            auto node = _stack.top();

            if(nullptr == node){
                _stack.pop();
                continue;
            }
            if( node->left ) {
                _stack.push(node->left);
                continue;
            }
            vec.push_back(node->val);
            _stack.pop();
            if( node->right ){
                _stack.push(node->right);
                continue;
            }
        }
    }
};