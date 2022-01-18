// MERA SOLUTION
class Solution {
public:
    int subtractProductAndSum(int n) {
        long int sum=0,prod=1; 
        while(n!=0){
           
            int digit=n%10;
            sum+=digit;
            prod*=digit;
            n=n/10;
        }
        return prod-sum;
        // cout<< prod-sum;
    }
};



// BABBAR SOLUTION
// class Solution {
// public:
//     int subtractProductAndSum(int n) {
        
//         int prod = 1;
//         int sum = 0;
        
//         while(n!=0) {
            
//             int digit = n%10;
//             prod = prod * digit;
//             sum = sum + digit;
            
//             n = n/10;
//         }
        
//         int answer = prod - sum;
//         return answer;
//     }
// };