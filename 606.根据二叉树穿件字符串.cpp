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
    string tree2str(TreeNode* t) {
        string s;
        if(t == NULL) return s;//终止条件

        if(t->left == NULL && t->right == NULL)
        {
            s.append(to_string(t->val));
            return s;
        }

        s.append(to_string(t->val));//根节点
        s+=("("+tree2str(t->left)+")");
        if(t->right!= NULL)
         s+=("("+tree2str(t->right)+")");
         return s;
    }
};
