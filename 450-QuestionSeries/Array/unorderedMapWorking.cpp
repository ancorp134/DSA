#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int arr[] = {12, 11, 40, 12, 5, 6, 5, 12, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    unordered_map<int, int> freq;
    for (int i=0; i<n; i++){
        // stores 1 in the value for corresponding 12 key
        freq[arr[i]]++;
        cout << freq[arr[i]] << " ";
    }
    //TRAVERSING THE UNORDERED_MAP
      for(auto i: freq){
        if(i.second>1)
            return i.first;
    }
        

    return 0;
}