// codestudio ==> https://www.codingninjas.com/codestudio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;
bool isCycle(vector<int>adj[],int i,vector<bool>vis,int parent){
//USING THE BFS
//     queue<pair<int,int>>q;
//     vis[i]=true;
//     q.push({i,-1});
//     while(!q.empty()){
//         int node=q.front().first;
//         int parent=q.front().second;
//         q.pop();
//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 vis[it]=true;
//                 q.push({it,node});
//             }
//             else if(it!=parent){
//                 return true;
//             }
//         }
//     }
//     return false;
//USING THE DFS
   vis[i]=true;
   for(auto it:adj[i]){
       if(!vis[it]){
           if(isCycle(adj,it,vis,i)){
               return true;
           }
       }
       else if(it!=parent){
           return true;
       }
   }
   return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
   // Write your code here.
   vector<int>adj[n+1];
   for(int i=0;i<m;i++){
       adj[edges[i][0]].push_back(edges[i][1]);
       adj[edges[i][1]].push_back(edges[i][0]);
   }
   vector<bool>vis(n+1,false);
   for(int i=1;i<=n;i++)
   {
       if(!vis[i]){
           if(isCycle(adj,i,vis,-1)){
               return "Yes";
           }
       }
   }
   return "No";
}
