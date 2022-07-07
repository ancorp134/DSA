// codestudio--> https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// Striver's code
// THIS IS CORRECT OUTPUT
//  just ordering problem
#include <bits/stdc++.h>
void breathFS(vector<int> adj[], vector<int> &vis, vector<int> &bfs, int node)
{
	queue<int> q;
	q.push(node);
	vis[node] = 1;
	while (!q.empty())
	{
		int frontnode = q.front();
		q.pop();
		bfs.push_back(frontnode);
		// traverse all the neighbours of the frontNode
		for (auto it : adj[frontnode])
		{
			if (!vis[it])
			{
				q.push(it);
				vis[it] = 1;
			}
		}
	}
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
	// Write your code here
	vector<int> bfs;
	vector<int> vis(vertex, 0);
	vector<int> adj[vertex + 1]; // converting 2D representation in a adjList
	for (auto i : edges)
	{
		adj[i.first].push_back(i.second);
		adj[i.second].push_back(i.first);
	}

	// traverse all components of a graph
	for (int i = 0; i < vertex; i++)
	{
		if (!vis[i])
		{
			breathFS(adj, vis, bfs, i);
		}
	}
	return bfs;
}

// babbar's code
#include <bits/stdc++.h>
using namespace std;
void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].insert(v);
		adjList[v].insert(u);
	}
}
void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = 1;

	while (!q.empty())
	{
		int frontNode = q.front();
		q.pop();

		// store frontNode into queue
		ans.push_back(frontNode);
		// traverse all the neighbours of the frontNode
		for (auto i : adjList[frontNode])
		{
			if (!visited[i])
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
	// Write your code here
	unordered_map<int, set<int>> adjList;
	vector<int> ans;
	unordered_map<int, bool> visited;
	// ajdList created
	prepareAdjList(adjList, edges);

	// traverse all components of a graph
	for (int i = 0; i < vertex; i++)
	{
		if (!visited[i])
		{
			bfs(adjList, visited, ans, i);
		}
	}
	return ans;
}