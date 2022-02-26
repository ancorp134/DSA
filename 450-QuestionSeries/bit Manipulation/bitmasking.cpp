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

int main()
{
    int n = 5;
    cout << "Is " << n << " odd? " << isOdd(n) << endl;
    cout << "getting bit at position 1: " << getBit(n, 1) << endl;
    cout <<"After setting 1st bit of n=5 =>" << setBit(n, 1) << endl;
    cout <<"After clearing 1st bit of n=5 =>" << clearBit(n, 1) << endl;
    cout <<"After toggling 1st bit of n=5 =>" << toggleBit(n, 1) << endl;

    return 0;
}