#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *l_node;
    struct node *r_node;
};

struct qnode{
    void *node;
    struct qnode *nextnode;
};

struct qnode *qroot=NULL;

void queueadd(void *qnnode){
    struct qnode *qnewnode = NULL;
    qnewnode=(struct qnode *)malloc(sizeof(struct qnode));
    qnewnode->node = qnnode; 
    qnewnode->nextnode = NULL;
    if(qroot==NULL)
    {
        qroot = qnewnode;
        return;
    }
    struct qnode *qtraverse = qroot;
    while (qtraverse->nextnode != NULL) {
        qtraverse = qtraverse->nextnode;
    }
    qtraverse->nextnode = qnewnode;
}

void* queuefetch(void)
{
    // FIX: Check if qroot is NULL before accessing its member
    if (qroot == NULL) { 
        return NULL;
    }
    struct qnode *prev=qroot;
     void *rt = prev->node;
    qroot=qroot->nextnode;
    return rt;
}

void queuedestroy(void){
    qroot=NULL;
}

struct node *root=NULL;
void add(int data){
    struct node *newnode=NULL;
    newnode = malloc(sizeof(struct node));
    newnode->data=data;
    newnode->l_node=NULL;
    newnode->r_node=NULL;
    if(root==NULL)
    {
        root = newnode;
        return;
    }
    if(root->l_node==NULL){
        root->l_node = newnode;
        return;
    }
    else{
        queueadd(root->l_node);
    }
    if(root->r_node==NULL){
        root->r_node = newnode;
        queuedestroy(); //destroy the queue
        return;
    }
    else{
        queueadd(root->r_node);
    }  
    //fetch from the queue 
    while(qroot!=NULL){
        struct node *fetchnode = (struct node *)queuefetch();
        if(fetchnode->l_node==NULL){
            fetchnode->l_node = newnode;
	        queuedestroy(); 
            return;
        }
        else{
            queueadd(fetchnode->l_node);
        }
        if(fetchnode->r_node==NULL){
            fetchnode->r_node = newnode;
            queuedestroy(); //destroy the queue
            return;
        }
        else{
            queueadd(fetchnode->r_node);
        } 
    }
}


int main()
{
    add(30);
    add(90);
    add(100);
    add(110);
    add(120);
    printf("data is %d \n",root->data);
    printf("data is %d \n",root->l_node->data);
    printf("data is %d \n",root->r_node->data);
    printf("data is %d \n",root->l_node->l_node->data);
    printf("data is %d \n",root->l_node->r_node->data);
    return 0;
}
