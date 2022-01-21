class Solution {
public:
    double myPow(double x, int n) {
       
        if(x==0)
            return 0;
        if(n==0)
            return 1;        
         if(n<0){
            n = -n;
            x = 1/x;
        }
        //since we had half the power we are doing x*x in case of even
        // in case of odd we just had to multiply by an extra x
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
        
    }
};