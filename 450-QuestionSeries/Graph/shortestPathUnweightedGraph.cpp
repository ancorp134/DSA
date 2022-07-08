//codestudio==>https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=3

// Why using vector<int> parent(n) is giving error in test case 4 but it works for unordered_map<int,int> parent??
#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	// Write your code here
    vector <int> adj[n+1];
   for(int i=0;i<m;i++)
   {
       adj[edges[i].first].push_back(edges[i].second);
       adj[edges[i].second].push_back(edges[i].first);
   }
    vector<int> vis(n,0);
    vector<int> parent(n);
    queue<int> q;
    q.push(s);
    vis[s]=1;
    parent[s]=-1;
 
   while(!q.empty())
   {
       int front = q.front();
       q.pop();
       for(auto child:adj[front])
       {
          if(!vis[child]){
              vis[child]=1;
              parent[child]=front;
              q.push(child);
          }
       }
   }
    //create shortest path
    vector<int> ans;
    int currentNode=t;
    ans.push_back(t);
    
    while(currentNode!=s){
    currentNode=parent[currentNode];
    ans.push_back(currentNode);
}
    reverse(begin(ans),end(ans));
    return ans;
}
