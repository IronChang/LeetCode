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
    vector<int> res;
    void inorder(TreeNode* root)
    {
        if(root == nullptr)
            return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }

};

class Solution {
public: 
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        while(root)
        {
            st.push(root);
            root = root->left;
        }
        while(!st.empty())
        {
            auto n = st.top();
            st.pop();
            res.push_back(n->val);
            for(n = n -> right;n;n=n->left)
            {
                st.push(n);
            }

        }
        return res;
    }

};