// leetcode ==> https://leetcode.com/problems/course-schedule/
https://www.codingninjas.com/codestudio/problems/1062626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

 bool isCycle(vector<int> adjList[],vector<int> &vis,int i) {        
        if (vis[i] == 0) {
            vis[i] = 1;
            for (auto neighbor : adjList[i]) {
                if (isCycle(adjList, vis, neighbor)) return true;
            }
        }
        else if (vis[i] == 1) return true;
        
        //mark it as visited but not in the current dfs
        vis[i] = 2;
        return false;
    }
    
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
     vector<int> adj[n+1];
    
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    vector<int> vis(n+1, 0);
    for(int i=1;i<n;i++){
        if(vis[i] == 0){
            if(isCycle(adj,vis,i)){
                return 1;
            }
        }
    }
     return 0;
}