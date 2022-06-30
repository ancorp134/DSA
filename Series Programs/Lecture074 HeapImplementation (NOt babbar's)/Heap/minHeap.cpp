// codestudio ==> https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

class Heap{    
    int arr[10000];
    int size ;
    public:
     Heap(){
        arr[0] = -1; //considered one base indexing
        size=0;
    }
    public:
    void push(int val){
        size++;
        int index = size;
        arr[index] = val;
        
        while(index > 1){
            int parent = index/2;
            
            if(arr[parent] > arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else
                return ;            
        }
        
    }
    public:
    int pop(){
        if(size==0)return -1 ;
        int deleteElement = arr[1];
        arr[1] = arr[size];
        size--;
        
        int i=1;
        while(i<=size){
            
            int leftind = 2*i;
            int rightind = 2*i +1;
            int smaller = i;
            if(leftind <= size && arr[leftind] < arr[smaller])
                smaller = leftind;
            
            if(rightind <= size && arr[smaller] > arr[rightind])
                smaller = rightind;
                
           if(i == smaller)break;
            
            swap(arr[i],arr[smaller]);
            i = smaller;
            
        }
        return deleteElement;
        
    }
    
    
};


vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    
    vector<int> ans;
    Heap minheap;//create minHeap
    
    for(auto it : q){        
        if(it[0]==0)
            minheap.push(it[1]);         
          
        else 
            ans.push_back( minheap.pop() );  //function returns element value            
    }
    return ans;
}
