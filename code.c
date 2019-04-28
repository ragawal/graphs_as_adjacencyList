#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//A structure representing a node in the adjacency list  
struct node{
	int next;
	int weight;
	struct node *next_node; 
};

//A structure representing adjacency list
struct nodeList{
	int vertex;
	struct node *head;
};

//A structure representing a graph of size V
struct graph{
	//int vertex;
	struct nodeList *list;
};

// A function to initialize the graph of V vertices. The head of all adjacenecy lists are assigned as NULL
struct graph* Create(int n){
	int i;
	
	struct graph *vertexList = malloc(sizeof(struct graph));;
	
	vertexList->list = malloc(sizeof(struct nodeList[n+1]));

	for(i = 0; i < n; i++)
	{	vertexList->list[i+1].vertex=i+1;
		vertexList->list[i+1].head = NULL;
	} 	
	
	return vertexList;
}

//A function to create a new node. Parameters include the weight of edge and the next node.
struct node* newNode(int value, int n){
	
	struct node *newNode = malloc(sizeof(struct node));;
	newNode->next=n;
	newNode->weight=value;
	newNode->next_node=NULL;

	return newNode;
}

// A function to insert the node at the head of the list
void insert(struct graph *G,int n1, int n2, int w){
	struct node *newnode1 = newNode(w,n2);

	if(G->list[n1].head==NULL)
	{
		G->list[n1].head=newnode1;
	}
	else
	{
		newnode1->next_node=G->list[n1].head;
		G->list[n1].head=newnode1;
	}
}

int main()
{
int i;
struct graph *G = Create(20);

FILE *inputfile;
int f;
inputfile=fopen("graph_info.txt", "r");
for(int i=0;i<20;i++){

	if(inputfile){
	int size=0;
	while(!feof(inputfile))
		{	fscanf(inputfile,"%d",&f);
			size++;
			if(f!=999){
			insert(G,i+1,size,f);}
			if(size>19)
				break;
		}
	}
}
fclose(inputfile);

for(i=0;i<20;i++)
{ printf("Adjance ist for node %d is \n ",i+1); 
while(G->list[i+1].head!=NULL)
	{ printf("vertex is %d ",G->list[i+1].vertex);
	  printf("weight is %d ",G->list[i+1].head->weight);
	  printf("next node is %d ",G->list[i+1].head->next);
	  //printf("%d ",G->list[i+1].head->next_node->weight);
	  //printf("%d ",G->list[i+1].head->next_node->next);
	//}
	G->list[i+1].head=G->list[i+1].head->next_node;
	}
	
}
return 0;
}
 	
