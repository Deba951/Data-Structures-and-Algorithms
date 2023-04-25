#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = NULL;  // Pointing or initialising root to Null

void insert(int item){

    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
    
    curr->lchild = NULL;
    curr->rchild = NULL;
    curr->data = item;
    
    if (root == NULL){
        root = curr;
        return;
    }

    struct Node *temp = root, *parent;

    while (temp!=NULL){
        parent = temp;
        
        if(item > temp->data)
            temp = temp->rchild;

        else
            temp = temp->lchild;
    }

    if(item > parent->data)
        parent->rchild = curr;

    else
        parent->lchild = curr;
}

void inOrder(struct Node*r){
    
    if (r!=NULL){
        inOrder(r->lchild);
        printf("%4d", r->data);
        inOrder(r->rchild);
    }
}

void preOrder(struct Node*r){
    
    if (r!=NULL){
        printf("%4d", r->data);
        preOrder(r->lchild);
        preOrder(r->rchild);
    }
}

void postOrder(struct Node*r){
    
    if (r!=NULL){
        postOrder(r->lchild);
        postOrder(r->rchild);
        printf("%4d", r->data);
    }
}

void search(int key){
    
    if (root == NULL){
            printf("Empty Tree\n");
            return;
    }
    
    struct Node *temp = root;
    
    while (temp != NULL){
        
        if (key == temp->data){
            printf("Found\n");
            return;
        }

        else if (key < temp->data)
            temp = temp->lchild;

        else
            temp = temp->rchild;
    }

    printf("Not Found\n");
}
//Delete




int main(){
    insert(10);
    insert(7);
    insert(3);
    insert(8);
    insert(15);
    insert(12);
    insert(20);
    insert(25);

    printf("\n ********* INORDER ********");
    inOrder(root);

    printf("\n ********* PREORDER ********");
    preOrder(root);

    printf("\n ********* POSTORDER ********");
    postOrder(root);
}