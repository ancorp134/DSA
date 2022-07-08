// codestudio==>https://www.codingninjas.com/codestudio/problems/920469?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int source) {
    // Write your code here.
    vector<pair<int,int>>adj[n];
    for(int i=0; i<edges; i++)
    {                            //node    , weight     
        adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
    }
    
    
    // Dijkstra's algorithm begins from here
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
    vector<int> distTo(n,INT_MAX);//1-indexed array for calculating shortest paths
    distTo[source] = 0;
    pq.push(make_pair(0,source));    // (dist,source)
    while( !pq.empty() ){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        for( auto it : adj[prev]){
            int next = it.first;
            int nextDist = it.second;
            if( distTo[next] > distTo[prev] + nextDist){
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }
//     cout << "The distances from source " << source << " are : \n";
//     for(int i = 1 ; i<=n ; i++)    cout << distTo[i] << " ";
//     cout << "\n";
    return distTo;
}
