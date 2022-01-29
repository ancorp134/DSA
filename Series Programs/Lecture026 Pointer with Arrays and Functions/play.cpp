//this code gives error or we say doesn't print anything as we are setting the value of ptr at address 0 i.e. not pointing to any value.
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int *ptr = 0;
    int a = 10;
    *ptr = a;
    cout << "a => ";
    cout << a << endl;
    cout << "ptr => " << *ptr << endl;
    return 0;
}