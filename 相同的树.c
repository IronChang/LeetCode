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


