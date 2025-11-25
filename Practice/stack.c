#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *nextnode;
};

struct node *top = NULL;

void init(int d)
{
    top=malloc(sizeof(struct node));
    top->data=d;
    top->nextnode = NULL;
}

void push(int d)
{
    struct node *push=NULL;
    push=malloc(sizeof(struct node));
    push->data=d;
    push->nextnode = top;
    top=push;
}

int pop(int d)
{
    struct node *pop=NULL;
    struct node *prev=NULL;

    if(top->data==d){
        top=top->nextnode;
        return 1;
    }

    for(pop=top;(pop!=NULL) && (pop->data!=d);pop=pop->nextnode){
        prev=pop;
    }
    
    prev->nextnode=pop->nextnode;
    return 0;
}


int main()
{
    init(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    pop(7);
    
    struct node *traverse;
    
    for(traverse=top;traverse!=NULL;traverse=traverse->nextnode){
        printf("data is %d \n",traverse->data);
    }
    

    // for(traverse=top;traverse!=NULL;traverse=traverse->nextnode){
    //     if(traverse->data=7){
    //         break;
    //     }
    // }
    // if(traverse==NULL) then print data not found else print below data
    // printf("data is %d \n",traverse->data);

    return 0;
}
