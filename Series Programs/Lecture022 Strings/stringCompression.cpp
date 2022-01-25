class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int ansIndex=0;
        int n=chars.size();
        
        while(i<n){
            int j=i+1;
            
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            
            //yahan tab ayenge
            //ya toh vector poora traverse kardia yaaa
            //ya toh element different h jo encounter kia
            
            //oldchar store kar lo
            chars[ansIndex++]=chars[i];
            
            int count=j-i;
            
            if(count>1){
                //counting ko string mein store kar rahe
                string cnt=to_string(count);
                for(auto ch:cnt)
                    chars[ansIndex++]=ch;
            }
            i=j;               
        }
        return ansIndex;
    }
};