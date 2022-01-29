#include<iostream>
using namespace std;

int main () {

    //pointer to int is created, and pointing to some garbage address so it is best to initialize the ptr to 0 or null
    //int *p = 0; 

    //cout << *p << endl;

    /* BOTH OF THESE METHODS ARE SAME
    1st method
    int i = 5;

    int *q = &i;
    cout << q << endl;
    cout << *q << endl;

    2nd method
    int *p = 0;
    p = &i;

    cout << p << endl;
    cout << *p << endl;
    */

   int num = 5;
   int a = num;
   cout << "a before " << num << endl;
   a++;
   cout << "a after " << num << endl;


   int *p  = &num;
   cout << "before " << num << endl;
   (*p)++;
   cout << "after " << num << endl;

    //copying a pointer
   int *q = p;
   cout << p <<" - " << q << endl;
   cout << *p <<" - " << *q << endl;

   //important concept
   int i = 3;
   int *t = &i;
   //cout <<  (*t)++ << endl;
   *t = *t +1;
    cout << *t << endl;
    //in this the address is increased by the size of data type of ptr
    cout << " before t " << t << endl;
    t = t + 1;
    cout << " after t " << t << endl;


    return 0;
}