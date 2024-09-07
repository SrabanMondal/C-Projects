#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node* add_node(Node *root,int data){
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL){
        return temp;
    }
    if(root->data<temp->data){
        root->right=add_node(root->right,data);
    }
    else{
        root->left=add_node(root->left,data);
    }
}
Node* finMin(Node *root){
    Node *temp=root;
    while (temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
Node* delete_node(Node *root, int value){
    if(root==NULL){
        return root;
    }
    if(root->data<value){
        root->right=delete_node(root->right,value);
    }
    else if(root->data>value){
        root->left=delete_node(root->left,value);
    }
    else{
        if(root->left==NULL&&root->right==NULL){
            Node* temp=root;
            root=NULL;
            free(temp);
            return root;
        }
        if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        Node* temp=finMin(root->right);
        root->data=temp->data;
        root->right=delete_node(root->right,temp->data);
    }
    return root;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}

bool checkbalance(Node* root,int* height){
    if(root==NULL){
        return true;
    }
    int lh=0, rh=0;
    bool l=checkbalance(root->left,&lh);
    bool r=checkbalance(root->right,&rh);
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    return false;
}
bool balance(Node* root){
    int height=0;
    return checkbalance(root,&height);
}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh,rh;
    lh=height(root->left);
    rh=height(root->right);
    return max(lh,rh)+1;
}
void postorder(Node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
Node* LCA(Node *root,int x, int y){
    if(root==NULL) return NULL;
    if(root->data>x && root->data>y){
        return LCA(root->left,x,y);
    }
    if(root->data<x && root->data<y){
        return LCA(root->right,x,y);
    }
    return root;
}
void levelorder(Node *root){
    if(root==NULL) return;
    Node *queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        Node* cur = queue[front++];
        printf("%d ",cur->data);
        if(cur->left!=NULL){
            queue[rear++]=cur->left;
        }
        if(cur->right!=NULL){
            queue[rear++]=cur->right;
        }
    }
}
int main(){
    Node *root=NULL;
    root = add_node(root,10);
    root = add_node(root,20);
    root = add_node(root,7);
    root = add_node(root,6);
    root = add_node(root,5);
    root = add_node(root,8);
    root = add_node(root,14);
    //root = delete_node(root,8);
    //root = delete_node(root,10);
    if(balance(root)){
        printf("Tree is balanced\n");
    }
    else{
        printf("Tree is not balanced\n");
    }
    printf("Height of the tree is %d\n",height(root));
    printf("LCA of 6 and 14 is %d\n",LCA(root,6,8)->data);
    postorder(root);
    printf("\n");
    levelorder(root);
}