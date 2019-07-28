/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(p == NULL && q == NULL)//递归结束条件
        return true;
    
    if(p == NULL || q == NULL)//其中有一个为空，则返回错误
        return false;
    
    if(p->val != q->val)//节点不相等，则返回错误
        return false;
    
    //递归
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);

}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    if(s == NULL)
        return false;
    
    if(s->val == t->val)
    {
        if(isSameTree(s,t) == true)
        return true;
    }
    
    return isSubtree(s->left,t) || isSubtree(s->right,t);

}



