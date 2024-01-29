#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left,*right;
}NODE;
NODE *create(NODE *root)
{
    NODE *temp,*parent,*newnode;
    int i,n;
    printf("enter limit");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       newnode=(NODE*)malloc(sizeof(NODE));
       printf("enter value");
       scanf("%d",&newnode->data);
       newnode->left=newnode->right=NULL;
       if(root==NULL)
       {
        root=newnode;
       }
      else
       {
         temp=root;
         while(temp!=NULL)
         {
             parent=temp;
             if(newnode->data>temp->data)
               temp=temp->right;
             else
               temp=temp->left;
         }
        if(newnode->data<parent->data)
            parent->left=newnode;
        else
            parent->right=newnode;
}
}
return root;
}
void inorder(NODE *root)
{
   	NODE *temp=root;
        if(temp!=NULL)
        {
          inorder(temp->left);
          printf("%d\t",temp->data);
          inorder(temp->right);
         }
}
NODE *deletetree(NODE *root,int num)
{
    NODE *temp;
    if(root==NULL)
     return root;
      if(num<root->data)
        root->left=deletetree(root->left,num);
      else if(num>root->data)
         root->right=deletetree(root->right,num);
      else if(num==root->data)
      {
         if(root->left==NULL)
           {
               temp=root->right;
                free(root);
                 return temp;
            }
           else if(root->right==NULL)
           {
               temp=root->left;
                free(root);
                return temp;
            }
           temp=root->right;
           while(temp&&temp->left!=NULL)
           {
              temp=temp->left;
           }
            root->data=temp->data;
            root->right=deletetree(root->right,temp->data);
        }
        return root;
}
int main()
{
    int num;
    NODE *root=NULL;
    root=create(root);
    inorder(root);
    printf("\nenter number to delete:");
    scanf("%d",&num);
    root=deletetree(root,num);
    inorder(root);
}
