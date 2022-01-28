// leetcode ==> count primes
// we are using sieve of eratosthenes
// Time Complexity: O(n*log(logn))
// Space Complexity: O(n)

class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        // as the count start from 0 and not from 1
        vector<bool> prime(n+1,true);
        //Set the element 0 and 1 to false
        prime[0]=prime[1]=false;
        
        for(int i=2;i<n;i++){
            if(prime[i])
                cnt++;
            
            for(int j=2*i; j<n ;j+=i){
                //setting the multiples to false we use 0 or false
                prime[j]=0;
            }
        }
        return cnt;
    }
};