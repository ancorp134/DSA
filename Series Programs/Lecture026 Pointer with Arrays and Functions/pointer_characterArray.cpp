#include<iostream>
using namespace std;

int main() {

    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";


    cout << arr << endl;
    //attention here
    cout << ch << endl;
    
    char *c = &ch[0];
    //prints entire string
    cout << c << endl;

    char temp = 'z';  //here it is a character not a charArray or string so no null character
    char *p = &temp;

    cout << p << endl;

// NEVER DO THIS
    //char *p = "abc";   IT will produce wrong output but will run fine so always create string using array not pointer
    return 0;
}