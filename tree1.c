#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node *left,*right;
}node;

node *create(node *root)
{
  int i,n;
  node *temp,*parent,*newnode;
  printf("enter limit");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
   newnode=(node*)malloc(sizeof(node));
   printf("enter value");
   scanf("%d",&newnode->data);
   newnode->left=NULL;
   newnode->right=NULL;
   if(root==NULL)
   {
    root=newnode;
    continue;
   }
   temp=root;
   while(temp!=NULL)
   {
     parent=temp;
     if(newnode->data<temp->data)
        temp=temp->left;
     else
        temp=temp->right;
    }
    if(newnode->data<parent->data)
      parent->left=newnode;
    else
      parent->right=newnode;
    }
    return root;
    }
    void inorder(node *root)
    {
      node *temp=root;
      if(temp!=NULL)
      {
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
      }
    }
    void preorder(node *root)
    {
       node *temp=root;
       if(temp!=NULL)
       {
         printf("%d\t",temp->data);
         preorder(temp->left);
         preorder(temp->right);
        }
       }
      void postorder(node *root)
      {
        node *temp=root;
        if(temp!=NULL)
        {
          postorder(temp->left);
          postorder(temp->right);
          printf("%d\t",temp->data);
        }
     }
     int main()
     {
       node *root=NULL;
       root=create(root);
       printf("\n inorder display");
       inorder(root);
       printf("\n preorder display");
       preorder(root);
       printf("\n postorder display");
        postorder(root);
}

