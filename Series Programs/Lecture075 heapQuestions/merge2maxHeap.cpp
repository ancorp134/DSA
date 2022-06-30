// codestudio ==> https://www.codingninjas.com/codestudio/problems/merge-two-binary-max-heaps_1170049?leftPanelTab=1

void heapify(vector<int> &arr, int n, int i){
    int largest =i;
    int left = 2*i+1;
    int right = 2*i +2;
    if(left<n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right <n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeap(vector<int> &arr1, vector<int> &arr2) {

    // Step 1: merge both arrays into one
    vector<int> ans;
    for(auto i:arr1)    ans.push_back(i);
    for(auto i:arr2)    ans.push_back(i);
    
    // Step 2: build heap using merged array
    int size = ans.size(); 
    for(int i=size/2-1; i>=0; i--){
        heapify(ans, size, i);
    }
    
    return ans;
    
}