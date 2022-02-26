#include<bits/stdc++.h>
using namespace std;

//Exponentiation by squaring
//T.C : O(log(n))
int fastExponentiation(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n % 2 == 0)
        return fastExponentiation(x * x, n / 2);
    else
        return x * fastExponentiation(x * x, (n - 1) / 2);
}   //end of fastExponentiation

//Exponentiation by using Bitwise operators
//T.C : O(log(n))
int fastExponentiationBitwise(int x, int n)
{
   int ans=1;
   while(n>0)
   {
       if(n&1) //if last bit is 1
       {
           ans=ans*x;
       }
       {
           ans=ans*x;
       }
       x=x*x;
       n=n>>1;
   }
}   //end of fastExponentiationBitwise

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<fastExponentiation(x,n);
    cout<<fastExponentiationBitwise(x,n);
    return 0;
}