class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
         sort(arr.begin(),arr.end());
        vector<int> v;
        for(int i=0;i<arr.size();i++)
        {
            int x=count(arr.begin(),arr.end(),arr[i]);
            v.push_back(x);
            i=i+x-1;
        }
        set<int> s(v.begin(),v.end());
        if(v.size()==s.size()) return true;
        return false;
    }
};