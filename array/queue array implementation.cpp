#include<iostream>
using namespace std;

bool isempty(int *front,int *rear)
{
	if(*front==-1 && *rear==-1)
	return true;
	
	return false;
}

void enqueue(int *arr,int key,int *front,int *rear,int N)
{
	if((*rear+1)%N==*front)
	return;
	
	else if(isempty(front,rear))
	{
		*front=0;
		*rear=0;
	}
	
	else
	{
		*rear=(*rear+1)%N;
	}
	arr[*rear]=key;
	
}

int deque(int *front,int *rear,int N)
{
	if(isempty(front,rear))
	return 0;
	
	int k=*front;
	
	if(*front==*rear)
	*front=*rear=-1;
	
	else
	*front=(*front+1)%N;
	
	return k;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int front=-1,rear=-1;
	enqueue(arr,5,&front,&rear,n);
}
