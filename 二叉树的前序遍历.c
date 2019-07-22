/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int * arr = NULL;
int size = 0;

void _preorderTraversal(struct TreeNode* root)
{
    //�ݹ���ֹ����
    if(root == NULL)
    {
        return;
    }
    
    //��ֵ
    arr[size++] = root->val;

    //�ݹ�
    _preorderTraversal(root->left);
    _preorderTraversal(root->right);
    
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* preorderTraversal(struct TreeNode* root, int* returnSize){

    arr = (int*) malloc(10000 * sizeof(int));
    size = 0;
    
    _preorderTraversal(root);
     
    *returnSize = size;
    return arr;
}


