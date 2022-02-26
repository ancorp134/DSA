#include <bits/stdc++.h>
using namespace std;

// we are provided with an array of integers and a positive integer
// size of the array
// and the size of the window is k
int main()
{
    int sum = 0;
    int i = 0; //(start of the window)
    int j = 0; //(end of the window)
    int maxi = 0;
    while (j < size)
    {
        sum = sum + arr[j];

        // we are moving the j pointer to the right to reach upto the size of the window
        // if we directly start j from the given size then we have to again calculate the sum of elements in btw i and j
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            // sum is important as we have reached the desired window size
            maxi = max(maxi, sum);
            // as we have to move the window forward by 1 element
            sum = sum - arr[i];
            i++;
            j++;
        }
    }
    return maxi;
}