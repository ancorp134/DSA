// codestudio ==> https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<bits/stdc++.h>
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    for(int i=0; i<k ; i++){
        for(int j=0; j< kArrays[i].size(); j++){
            minh.push(kArrays[i][j]);
        }
    }
    vector<int> res;
    while(minh.size() > 0) {
        res.push_back(minh.top());
        minh.pop();
    }  
    return res;
}