#include<bits/stdc++.h>
class Solution {
public:
    string removeDuplicates(string s) {
        
        //this fails if on input of this type ==> "aaaaaaaaaa"   10 times a but works fine for 9 times a 
        for(int j=0;j<s.size();j++){
          for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1] && s.size()==2){
                s.erase(s.begin(),s.end());
                break;
            }                 
            if(s[i]==s[i+1]){
               s.erase(s.begin()+i,s.begin()+i+2);
            }
        }  
    }        
        return s;
        
        //Another Approach Easy method in O(n)
        // string res = "";
        // for (char c : s) {
        //     if (!res.empty() && res.back() == c) {
        //         res.pop_back();
        //     } else {
        //         res.push_back(c);
        //     }
        // }
        // return res;
    }
};