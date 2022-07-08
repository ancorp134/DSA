// codestudio==> https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h>
using namespace std;

stack<int> s;
void dfs(vector<int> adj[], int node, vector<bool> &vis)
{
    vis[node] = 1;

    for (int child : adj[node])
    {
        if (!vis[child])
            dfs(adj, child, vis);
    }

    s.push(node);
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    vector<int> adj[v];
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> vis(v, 0);
    // STEP 1 TOPO SORT
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(adj, i, vis);
    }

    vector<int> res;
    while (!s.empty())
        res.push_back(s.top()), s.pop();

    // CLEAR THE ADJACENCY LIST
    for (int i = 0; i < v; i++)
        vis[i] = 0, adj[i].clear();

    // STEP 2 REVERSE EDGES (TRANSPOSE)
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    // STEP 3 DFS ON THE REVERSE EDGES
    int ans = 0;
    for (int i = 0; i < v; i++)
    {
        if (!vis[res[i]])
            dfs(adj, res[i], vis), ans++;
    }

    return ans;
}