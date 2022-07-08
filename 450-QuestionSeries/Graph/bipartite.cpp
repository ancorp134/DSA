
// BIPARTITE GRAPH USING DFS
#include <bits/stdc++.h>
using namespace std;
// vector<int> adj[];
vector<int> calar;
vector<int> vis;
bool bipart=true;
void colorkaro(int u, int curr, vector<int> adj[])
{
    // agar current node already colored h aur uska color curr k equal nhi h toh nhi bipartite h
    if (calar[u] != -1 && calar[u] != curr)
    {
        bipart = false;
        return;
    }
    calar[u] = curr;
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    for (auto i : adj[u])
    {
        colorkaro(i, 1 - curr, adj);
    }
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vis.resize(n, 0);
    calar.resize(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            colorkaro(i, 0, adj);
        }
    }
    if (bipart)
        cout << "Graph is bipart";
    else
        cout << "Graph is not bipartite";
}