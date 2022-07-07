// codestudio==>https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?topList=striver-sde-sheet-problems&leftPanelTab=0

void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &res){
   res.push_back(node);//store the node which are connected in a linear way
    vis[node]=1;//mark the node as visited
    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(i,vis,adj,res);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int>vis(V,0);
    vector<vector<int>> res;
    vector<int> adj[V+1];//converting the 2D representation in a adjList
    for(int i = 0;i<E;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }//designing the adjacency list
    
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            //everytime make a new container
            //if the nodes are unvisited then a separate vector will form
            vector<int> eachNode;
            dfs(i,vis,adj,eachNode);
            res.push_back(eachNode);
        }
    }
    //no need to return size as it is printed automatically
    return res;
}