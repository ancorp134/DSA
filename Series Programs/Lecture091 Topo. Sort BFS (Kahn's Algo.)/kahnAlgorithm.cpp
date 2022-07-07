https://www.codingninjas.com/codestudio/problems/982938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h>
// using kahn's algorithm  BFS
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v+1] ; 
    for( int i =0 ; i < edges.size();i++){
    // making the adj list for the directed graph
     adj[edges[i][0]].push_back(edges[i][1]);     
    }
   vector<int> ans ; 
   vector<int> indegree(v,0);
     for(int i = 0;i<v;i++) {
            for(auto it: adj[i]) {
                indegree[it]++; 
            }
        }
    queue<int> q ; 
    for( int i =0 ; i < v ; i++)
        if(indegree[i]==0) q.push(i);   
    
    // performing bfs 
    while(!q.empty())
    {
        int f = q.front(); 
        q.pop(); 
        ans.push_back(f);
        for(auto i : adj[f])
        {
            indegree[i]--;
            if(indegree[i]==0)    q.push(i); 
            }
        }   
    return ans; 
}


//DFS
// void findTopoSort(int node, vector<int>&vis, stack<int>&st, vector<int>adj[]) {
//     vis[node] = 1;
//     for (auto it: adj[node]) {
//       if (!vis[it]) {
//         findTopoSort(it, vis, st, adj);
//       }
//     }
//     st.push(node);
//   }

// vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
//    vector<int>adj[v+1];    
//     for(int i=0;i<e;i++){
//         adj[edges[i][0]].push_back(edges[i][1]);
//     }
//    stack < int > st;
//    vector< int > vis(v, 0);
//       for (int i = 0; i < v; i++) {
//         if (vis[i] == 0) {
//           findTopoSort(i, vis, st, adj);
//         }
//       }
//       vector < int > topo;
//       while (!st.empty()) {
//         topo.push_back(st.top());
//         st.pop();
//       }
//       return topo;
// }