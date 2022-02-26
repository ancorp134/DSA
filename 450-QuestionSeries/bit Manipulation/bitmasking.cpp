// number == > 1 0 1 0 1
//index   == > 4 3 2 1 0

#include <bits/stdc++.h>
using namespace std;

// TO check for odd or even number
//  n&1 == 1 if n is odd
//  n&1 == 0 if n is even
bool isOdd(int n)
{
    return n & 1;
}

// To get the bit at the given position  (Right to left)
int getBit(int n, int pos)
{
    //1st method to get the bit
    // return (n >> pos) & 1;

    //2nd method to get the bit
    int mask = 1 << pos;
    int bit = (n & mask) > 0 ? 1 : 0;
    return bit;
}

// To set the bit at the given position (Right to left) i.e always make it 1
int setBit(int &n, int pos)
{
    //1st method to set the bit
    // return (n | (1 << pos));

    //2nd method to set the bit
    int mask = 1 << pos;
    return n | mask;
}

// To clear the bit at the given position (Right to left)  i.e. make it 0
int clearBit(int &n, int pos)
{
    //1st method to clear the bit
    // return (n & ~(1 << pos));

    //2nd method to clear the bit
    int mask = ~(1 << pos);
    return n & mask;
}

// To toggle the bit at the given position (Right to left)  i.e if it is 1 then make it 0 and vice versa
int toggleBit(int &n, int pos)
{
    //1st method to toggle the bit
    // return (n ^ (1 << pos));

    //2nd method to toggle the bit
    int mask = 1 << pos;
    return n ^ mask;
}

//to clear the last i bits of the number i.e. set them to 0 (Right to left)
// 2^x se jo b number 1 number kam hoga woh all zero hoga
int clearLastNBits(int n, int pos)
{
    //1st method to clear the last n bits
    // return (n & ~((1 << pos) - 1));

    //2nd method to clear the last n bits
    int mask = ~((1 << pos) - 1);
    return n & mask;
} 

//to clear the bits in the range from i to j (Right to left) i.e. set them to 0
//paper par karke hi dekhna padega ek baar 😁
int clearRange(int n, int i, int j)
{
    //1st method to clear the range
    // return (n & ~((1 << j) - 1) & ~((1 << i) - 1));

    //2nd method to clear the range
    int mask = ~((1 << j) - 1) & ~((1 << i) - 1);
    return n & mask;
}

int main()
{
    int n = 5;  //5 ==> 101
    cout << "Is " << n << " odd? " << isOdd(n) << endl;
    cout << "getting bit at position 1: " << getBit(n, 1) << endl;
    cout <<"After setting 1st bit of n=5 =>" << setBit(n, 1) << endl;
    cout <<"After clearing 1st bit of n=5 =>" << clearBit(n, 1) << endl;
    cout <<"After toggling 1st bit of n=5 =>" << toggleBit(n, 1) << endl;
    n=15;  // 15 ==> 1111
    cout <<"After clearing last 2 bits of n=15 =>" << clearLastNBits(n, 2) << endl;
    cout <<"After clearing range from 2 to 4 of n=15 =>" << clearRange(n, 0, 1) << endl;

    return 0;
}