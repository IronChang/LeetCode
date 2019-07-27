#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef char BTDataType;
typedef struct TreeNode
{
    BTDataType val;
    struct TreeNode* left;//左节点
    struct TreeNode* right;//右节点
}Node;

Node* BuyNode(BTDataType data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    assert(newnode);
    newnode->val = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

Node* CreateTree(char* a,int* index)
{
    if(a[*index] == '#' )
    {
        ++(*index);
        return NULL;
    }  
    
    Node* root = BuyNode(a[*index]);
    ++(*index);
    
    root->left = CreateTree(a,index);
    root->right = CreateTree(a,index);
    
    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%c ",root->val);
    inorder(root->right);
}
int main()
{
    BTDataType* arr[100];
    scanf("%s",arr);
    //构建树
    int index = 0;
    Node* root = CreateTree(arr,&index);
    inorder(root);
    
    return 0;
}
