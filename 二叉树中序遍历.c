/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int *arr = NULL;
int size = 0;

void _inorderTraversal(struct TreeNode* root)
{
   if(root == NULL)
   {
       return;
   }
    
    _inorderTraversal(root->left);
    
    arr[size++] = root->val;
    
    _inorderTraversal(root->right);


}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    
    arr = (int*)malloc(sizeof(int)*10000);
    size = 0;
    
    _inorderTraversal(root);
    
    
    *returnSize = size;
    return arr;

}


