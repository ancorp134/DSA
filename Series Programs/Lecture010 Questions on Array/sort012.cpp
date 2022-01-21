leetcode ==> SortColors
codeStudio ==> sort 0 1 2

class Solution {
public:
    void sortColors(vector<int>& arr) {
        //1ST APPROACH
          int czero = 0, cone = 0, ctwo = 0; 
          int n=arr.size();
          for(int i=0; i<n; i++){
              if(arr[i]==0)
                  czero++;
              if(arr[i]==1)
                  cone++;
              if(arr[i]==2)
                  ctwo++;
          }
         int i=0;
   while (0 < czero){
       arr[i++]=0;
       czero--;

   }
   while (0 < cone){
       arr[i++]=1;
       cone--;
   }
   while (0 <ctwo){
       arr[i++]=2;
       ctwo--;
   }
        
        // 2ND APPROACH USING THE STL SORT
        // int n=arr.size();
        // sort(arr.begin(),arr.end());
       }
};