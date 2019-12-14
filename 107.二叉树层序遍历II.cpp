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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty())
        {
            int len = qu.size();
            vector<int> tmp;
            for(int i = 0;i<len ;i++)
            {
               TreeNode* node = qu.front();
               qu.pop();
               tmp.push_back(node->val);
               if(node -> left) qu.push(node->left);
               if(node -> right) qu.push(node->right); 
            }
            res.push_back(tmp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
