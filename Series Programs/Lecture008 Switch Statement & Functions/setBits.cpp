#include <iostream>
using namespace std;

int countSetBits(int x)
{
  int count = 0;

  while(x!=0)
  {
    if(x&1)
    {
      count++;
    }
    x=x>>1;
  }
  return count; 
}


int main()
{
  int a,b;
  cin>>a>>b;

  int ans1=countSetBits(a);
  int ans2=countSetBits(b);

  cout<<"Set bits of A="<<ans1<<endl;
  cout<<"Set bits of B="<<ans2<<endl;

  int ans=ans1+ans2;
  cout<<"Total set bits of A and B are ="<<ans<<endl;
  return 0;

}
