#include <bits/stdc++.h>
using namespace std;

// 1st Method
// last bit agar 1 h toh count badhaate jaao
// T.C : in any Number we can have at most Log(N) +1 bits
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n = n >> 1;
    }
    return count;
}

// 2nd Method
// n & (n-1) will clear the last set bit in right to left manner
//T.C. : will be almost equal to O(1) as while loop iteration is based on the number of setbits in the number
int countSetBitsFast(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

// 3rd Method
// built in method
int countSetBitsBuiltIn(int n)
{
    return __builtin_popcount(n);
}

int main()
{
    int n = 5;
    cout << countSetBits(n);
    cout << countSetBitsFast(n);
    cout << countSetBitsBuiltIn(n);
    return 0;
}