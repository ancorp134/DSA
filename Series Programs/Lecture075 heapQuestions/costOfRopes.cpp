// codestudio ==>https://www.codingninjas.com/codestudio/problems/connect-n-ropes-with-minimum-cost_630476?leftPanelTab=1

long long connectRopes(int* arr, int n)
{
    // Your code goes here
        priority_queue < int, vector<int>, greater<int>> pq(arr, arr+n);
        long long int cost=0;
        
        while(pq.size()>1){
            int A=pq.top();
            pq.pop();
            
            int B=pq.top();
            pq.pop();
            
            int new_rope=(A+B);
            cost+=new_rope;
            pq.push(new_rope);
 
        }
        return cost;
}
