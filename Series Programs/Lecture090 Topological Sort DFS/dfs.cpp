// codestudio ==> https://www.codingninjas.com/codestudio/problems/982938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h>
//DFS
void findTopoSort(int node, vector<int>&vis, stack<int>&st, vector<int>adj[]) {
    vis[node] = 1;
    for (auto it: adj[node]) {
      if (!vis[it]) {
        findTopoSort(it, vis, st, adj);
      }
    }
    st.push(node);
  }

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   vector<int>adj[v+1];    
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
   stack < int > st;
   vector< int > vis(v, 0);
      for (int i = 0; i < v; i++) {
        if (vis[i] == 0) {
          findTopoSort(i, vis, st, adj);
        }
      }
      vector < int > topo;
      while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
      }
      return topo;
}