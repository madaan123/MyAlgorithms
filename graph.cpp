#include<bits/stdc++.h>
using namespace std;

class Graph{
	private:
		vector<vector<int> >graph;
		int n;
		vector<bool> visit;
		void dfsAux(int v);
		void RecursiveDfs(int v);
	public:
		Graph(int size)						// initializing the graph
		{
			n=size;
			graph.resize(n);
			visit.resize(n);
		}
		
		void addEdge(int s,int d)			// function to add an edge to the graph
		{
			graph[s].push_back(d);
		}
		
		void bfs();			// breadth first search function
		void dfs1();		// iterative depth first search function
		void dfs2();		// recursive depth first search function
};

void Graph::bfs()							// breadth first search
{
	queue<int>bfsQueue;
	fill(visit.begin(),visit.end(),0);
	
	for(int i=0;i<n;i++)
	{
		if(visit[i]==false)
		{
			visit[i]=true;
			bfsQueue.push(i);
			while(!bfsQueue.empty())
			{
				int v=bfsQueue.front();
				bfsQueue.pop();
				
				cout<<"visited node is "<<v<<endl;
				for(vector<int>::iterator iter=graph[v].begin();iter!=graph[v].end();iter++)
				{
					if(visit[*iter]==false)
					{
						visit[*iter]=true;
						bfsQueue.push(*iter);
					}
				}
			}
		}
	}
}

void Graph::dfsAux(int i)					// iterative depth first search
{
	stack<int>DFS;
	DFS.push(i);
	while(!DFS.empty())
	{
		int v=DFS.top();
		DFS.pop();
		if(visit[v]==true)
		continue;
		
		visit[v]=true;
		cout<<"visited node is "<<v<<endl;
		for(vector<int>::iterator iter=graph[v].begin();iter!=graph[v].end();iter++)
		{
			if(visit[*iter]!=true)
			{
				DFS.push(*iter);
			}
		}
	}
}

void Graph::dfs1()
{
	fill(visit.begin(),visit.end(),0);
	for(int i=0;i<n;i++)
	{
		if(visit[i]==false)
		{
			dfsAux(i);
		}
	}
}

void Graph::RecursiveDfs(int v)						// recursive depth first search
{
	visit[v]=true;
	cout<<"visited node is "<<v<<endl;
	for(vector<int>::iterator iter=graph[v].begin();iter!=graph[v].end();iter++)
	{
		if(visit[*iter]==false)
		{
			RecursiveDfs(*iter);
		}
	}
}

void Graph::dfs2()
{
	fill(visit.begin(),visit.end(),0);
	for(int i=0;i<n;i++)
	{
		if(visit[i]==false)
		{
			RecursiveDfs(i);
		}
	}
}

int main()
{
	Graph obj(8);
	int s,d;
	obj.addEdge(0,1);
	obj.addEdge(0,2);
	obj.addEdge(1,3);
	obj.addEdge(1,4);
	obj.addEdge(2,5);
	obj.addEdge(4,6);
	obj.addEdge(4,7);
	obj.bfs();						// printing breadth first search
	obj.dfs1();						// printing depth first search by iterative function
	obj.dfs2();						// printing depth first search bu recursive function
}
