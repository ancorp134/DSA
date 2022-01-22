void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i=0;i<n-1;i++){
        //given all the values are +ve
        int minValue=i;
        for(int j=i+1;j<n;j++){
            if(arr[minValue]>arr[j])
                minValue=j;
        }
        swap(arr[i],arr[minValue]);
      }
}