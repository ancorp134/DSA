#include <bits/stdc++.h>
// #include <iostream>
using namespace std;

void swapAlternate(int arr[], int size)
{

    for (int i = 0; i < size; i = i + 2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    swapAlternate(arr, 7);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}