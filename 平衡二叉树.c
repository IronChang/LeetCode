/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root)
{    int left = 0;
    int right = 0;
    
  if(root == NULL)
      return 0;
    
    left = maxDepth(root->left);
    right = maxDepth(root->right);
    
    return left>right?left+1:right+1;
}

bool isBalanced(struct TreeNode* root)
{
    int left = 0;
    int right = 0;
    
    if(root == NULL)
        return true;

    //�������¼��ÿһ���ڵ�����������߶ȣ�Ч�ʲ�ظ����˸߶�
    left = maxDepth(root->left);
    right = maxDepth(root->right);
    
    return abs(right - left)<2 && isBalanced(root->left) && isBalanced(root->right);

    
}


