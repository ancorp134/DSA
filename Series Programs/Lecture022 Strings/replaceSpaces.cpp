#include<string>
#include<iostream>
using namespace std;

//MY APPROACH
string replaceSpaces(string &str){
	// Write your code here.
      string s;
        for(int i=0;i<str.length();i++){
            if(str[i]== ' '){
                s+="@40";
                continue;
            }
            s+=str[i];
        }
        return s;
}


// string replaceSpaces(string &str){
// 	string temp = "";
    
//     for(int i=0; i<str.length(); i++) {
//         if(str[i] == ' '){
//             temp.push_back('@');
//             temp.push_back('4');
//             temp.push_back('0');
//         }
//         else
//         {
//             temp.push_back(str[i]);
//         }
//     }
//     return temp;
// }