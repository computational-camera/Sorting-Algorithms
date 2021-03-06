/************************************************************************/
/* Linklist                                                             */
/*                                                                      */
/* linklist.h                                                           */
/* Copyright 2002-2018                                                  */
/*                                                                      */
/* Permission is hereby granted, free of charge, to any person          */
/* obtaining a copy of this software and associated documentation       */
/* files (the "Software"), to deal in the Software without restriction, */
/* including without limitation the rights to use, copy, modify, merge, */
/* publish, distribute, sublicense, and/or sell copies of the Software, */
/* and to permit persons to whom the Software is furnished to do so,    */
/* subject to the following conditions:                                 */
/*                                                                      */
/* The above copyright notice and this permission notice shall be       */
/* included in all copies or substantial portions of the Software.      */
/*                                                                      */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,      */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF   */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                */
/* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  */
/* BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN   */
/* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN    */
/* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE     */
/* SOFTWARE.                                                            */
/*                                                                      */
/************************************************************************/
#ifndef _LINKEDLIST
#define _LINKEDLIST

#define NULL  0
#define MAX 100

typedef char DataType[MAX];

typedef struct node{
    DataType data;      
    struct node *next;
}ListNode;

typedef ListNode *LinkList;
ListNode *r,*s;             /*Link node pointers*/
LinkList head;              /*Header pointer*/

LinkList CreatList(){       /*Creat linked list*/
    DataType ch;
    printf("Please input link list, use END as finish \n");
    head=(LinkList)malloc(sizeof(ListNode));
    s=head;
    while (strcmp(ch,"END")){   /*Linked list tail flag*/
        r=(ListNode*)malloc(sizeof(ListNode));
        gets(ch);
        strcpy((r->data),ch);
        s->next=r;
        s=r;
    }
    s->next=NULL;
    return head;
}

void Display(){             /*Display the linked list*/
    DataType ch;
    printf("Linked list elements");
    s=head->next;
    strcpy(ch,(s->data));
    printf("BEGIN");
    while((s->next)!=NULL){
        printf("-->");
        printf("%s",ch);
        s=s->next;
        strcpy(ch,s->data);
    }
    printf("-->%s\n",ch);
}

ListNode *GetNode(LinkList head,int i){        /*Find node element*/ 
    int j=0; s=head;
    while(s->next&&j<i){
        s=s->next;
        j++;
    }
    if(i==j)
    return s;
    else return NULL;
}

CheckList(DataType x){                        /*Check (repeat) node*/
    int i=0;
    s=head;
    while(s->next!=NULL){
        if(!strcmp((s->next->data),x)){
            printf("Node already exit \n",x);
            i++;
        }
        s=s->next;
    }
    return i;
}


void InsertList(){                             /*Insert node*/
    int i;
    DataType x,pool;
    printf("Insert node \n");
    scanf("%s",&x);
    printf("Input position \n");
    scanf("%d",&i);
    gets(pool);
    if(!CheckList(x)){
        r=GetNode(head,i-1);
        if(r==NULL||r->next==NULL)
            printf("\n");
        else {
            s=(ListNode *)malloc(sizeof(ListNode));
            strcpy(s->data,x);
            s->next=r->next;
            r->next=s;
        }
    }
}

void DeleteList(){                            /*Delete a node*/
    DataType x;
    int i=1;
    char ch;
    s=head;
    printf("Input the string (node) to delete\n");
    scanf("%s",&x);
    while(strcmp(x,s->next->data)&&(s)) 
        {s=s->next;i++;}
    if((!s)||(!strcmp(x,"END"))) 
        printf("Not able to find the node %s!\n",x);
    else{
        printf("The position of the node is %d\n",i);
        printf("Delete, confirm (y,n)\n");
        scanf("\n%c",&ch);
        if(ch=='y') {
            r=s->next;
            s->next=s->next->next;
            free(r);
        }
    }
}

void Menu(){                     
char i;
A: printf("Choose Option\n");
    printf("a.Insert\n");
    printf("b.Delete\n");
    printf("c.Finish\n");
    scanf("\n%s",&i);
    if(i=='a'){
        InsertList();
        Display();
        goto A;
    }
    else if(i=='b'){
        DeleteList();
        Display();
        goto A;
    }
    else if(i=='c')
        printf("Thank You \n");
    else {
        printf("Choose Option Agagin\n");
        goto A;
    }
}

#endif
