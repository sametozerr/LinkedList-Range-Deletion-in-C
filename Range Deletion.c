/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

/* Note: I just add the deleteNodes function.
/* All the other codes belongs the Deepali Srivastava as mention above.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *createList(struct node *start);
void displayList(struct node *start);
void countNodes(struct node *start);
void search(struct node *start,int x);
struct node *insertInBeginning(struct node *start,int data);
void insertAtEnd(struct node *start,int data);
void insertAfter(struct node *start,int data,int x);
struct node *insertBefore(struct node *start,int data,int x );
struct node *insertAtPosition(struct node *start,int data,int k);
struct node *deleteNode(struct node *start,int data);
struct node *reverseList(struct node *start);
struct node * deleteNodes(struct node * start, int first, int last);


int main()
{
	struct node *start=NULL, * second = NULL, * third = NULL;
	
	int choice,data,x,k;
	
	int i;
	
	start = insertInBeginning(start,1);
	second = insertInBeginning(second,1);
	third = insertInBeginning(third,1);
	
	for(i = 2; i <= 5; i++) 
	{
	    insertAtEnd(start, i);
	    insertAtEnd(second, i);
	    insertAtEnd(third, i);
	}
    
    /*
    start = deleteNodes(start, 1, 3);
    second = deleteNodes(second, 2, 4);
    third = deleteNodes(third, 3, 5);
    */

	start = deleteNodes(start, 3, 6);
    second = deleteNodes(second, 6, 8);
    third = deleteNodes(third, 3, 3);

    displayList(start);
	displayList(second);
	displayList(third);

	/*
	while(1)
	{
		printf("\n");
		printf("1.Display list\n");
		
		printf("2.Count the number of nodes\n");
		printf("3.Search for an element\n");
		printf("4.Insert in empty list / Insert in beginning of the list\n");
		printf("5.Insert a node at the end of the list\n");
		printf("6.Insert a node after a specified node\n");
		printf("7.Insert a node before a specified node\n");
		printf("8.Insert a node at a given position\n");
		printf("9.Delete a node\n");
		printf("10.Reverse the list\n");
		printf("11.Quit\n\n");
		
		
		printf("Enter your choice : ");
		scanf("%d",&choice);

		if(choice==11)
			break;

		switch(choice)
		{
		 case 1:
			displayList(start);
			displayList(second);
			displayList(third);
			break;
		 case 2:
			countNodes(start);
			break;
		 case 3:
			printf("Enter the element to be searched : ");
			scanf("%d",&data);
			search(start,data);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=insertInBeginning(start,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			insertAtEnd(start,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&x);
			insertAfter(start,data,x);
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert : ");
			scanf("%d",&x);
			start=insertBefore(start,data,x);
			break;
		 case 8:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the position at which to insert : ");
			scanf("%d",&k);
			start=insertAtPosition(start,data,k);
			break;
		 case 9:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			start=deleteNode(start, data);	
			break;
		 case 10:
			start=reverseList(start);
			break;
		 default:
			 printf("Wrong choice\n");
		}
	}
	*/
}/*End of main()*/

struct node * deleteNodes(struct node * start, int first, int last)  
{
    
    if(first <= 0 || last <= 0)
        return start;
    
    struct node * p, * preFirst, * temp;
    int position;
    
    /*
    
    /* p: D���mler aras�nda gezinmemizi sa�lar.
    /* preFirst: Silinecek olan ilk d���mden �nceki d���m� i�erisinde tutar.
    /* temp: Silinecek olan d���m� i�erisinde tutar.
    /* position: Silinecek olan d���m�n pozisyonunu i�erisinde tutar.
    
    */
       
    p = start;
    preFirst = start;
    position = 1;
    
    // Silinecek olan ilk d���mden �nceki d���m� bulmaya �al���yoruz.
    while(position <= first - 1) 
    {
        if(position == first - 1)
            preFirst = p;
        
        if(p->link == NULL)
            return start;
        
        p = p->link;
        
        position++;
    }
    
    while(position <= last) 
    {
        temp = p;
        p = p->link;
        
        if(p == NULL)
            break;
        
        free(temp);
        position++;
    }
    
    if(first == 1)
        start = p; 
    
    else if(p == NULL) 
        preFirst->link = NULL;
        
    else 
        preFirst->link = p;   
    
    return start;
    
} 

void insertAfter(struct node *start,int data,int x)
{
	struct node *temp,*p;
	
	p=start;
	while(p!=NULL)
	{
		if(p->info==x)
			break;
		p=p->link;
	}
	
	if(p==NULL)
		printf("%d not present in the list\n",x);
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=p->link;
		p->link=temp;
	}
}

struct node *insertBefore(struct node *start,int data,int x)
{
	struct node *temp,*p;
	
	/*If list is empty*/
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}	
	
	/*x is in first node,new node is to be inserted before first node*/
	if(x==start->info)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=start;
		start=temp;
		return start;
	}	
	
	/*Find pointer to predecessor of node containing x*/
	p=start;
	while(p->link!=NULL) 
	{
		if(p->link->info==x)
			break;	
		p=p->link;
	}
	
	if(p->link==NULL)
		printf("%d not present in the list\n",x);
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=p->link;
		p->link=temp;
	}
	return start;
}

struct node *insertAtPosition(struct node *start,int data,int k)
{
	struct node *temp,*p;
	int i;
	
	if(k==1)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=start; 
		start=temp;
		return start;
	}
	
	p=start;
	for(i=1; i<k-1 && p!=NULL; i++) /*find a pointer to k-1 node*/
		p=p->link;
    
	if(p==NULL)
		printf("You can insert only upto %dth position\n\n",i);
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=p->link;
		p->link=temp;
	}	
	return start;
}

struct node *createList(struct node *start)
{
	int i,n,data;

	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	
	if(n==0)
		return start;

	printf("Enter the first element to be inserted : ");
	scanf("%d",&data);
	start=insertInBeginning(start,data);

	for(i=2; i<=n; i++)
	{
		printf("Enter the next element to be inserted : ");
		scanf("%d",&data);
		insertAtEnd(start,data);	
	}
	return start;
}/*End of createList()*/

struct node *insertInBeginning(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;

	temp->link=start;
	start=temp;
	
	return start;
}

void insertAtEnd(struct node *start,int data)
{
	struct node *p,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;

	p=start;
	while(p->link!=NULL)
		p=p->link;
	
	p->link=temp;
	temp->link=NULL;
}

void displayList(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("List is :   ");
	p=start;
	while(p!=NULL)
	{
		printf("%d  ",p->info);
		p=p->link;
	}
	printf("\n");
}/*End of displayList()*/

void countNodes(struct node *start)
{
	int n=0;
	struct node *p=start;
	while(p!=NULL)
	{
		n++;
		p=p->link;
	}
	printf("Number of nodes in list = %d\n",n);
}/*End of countNodes() */

void search(struct node *start,int x)
{
	struct node *p;
	
	int position=1;
	p=start;
	while(p!=NULL)
	{
		if(p->info==x)
			break;	
		position++;
		p=p->link;
	}
	if(p==NULL)
		printf("%d not found in list\n",x);
	else
		printf("%d is at position %d\n",x,position);	
}/*End of search()*/

struct node *deleteNode(struct node *start,int x)
{
	struct node *temp,*p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	/*Deletion of first node*/
	if(start->info==x)
	{
		temp=start;
		start=start->link;  
		free(temp);
		return start;
	}
	/*Deletion in between or at the end*/
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==x)   
			break;	
		p=p->link;
	}
	
	if(p->link==NULL)
		printf("Element %d not in list\n\n",x);
	else
	{
		temp=p->link;
		p->link=temp->link;
		free(temp);
	}
	return start;
}

struct node *reverseList(struct node *start)
{
	struct node *prev, *ptr, *next;
	prev=NULL;
   	ptr=start;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	return start;
}/*End of reverseList()*/
