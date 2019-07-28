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
    if(p == NULL && q == NULL)//�ݹ��������
        return true;
    
    if(p == NULL || q == NULL)//������һ��Ϊ�գ��򷵻ش���
        return false;
    
    if(p->val != q->val)//�ڵ㲻��ȣ��򷵻ش���
        return false;
    
    //�ݹ�
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



