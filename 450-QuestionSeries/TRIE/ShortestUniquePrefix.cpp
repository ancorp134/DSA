// codestudio ==> https://www.codingninjas.com/codestudio/problems/shortest-unique-prefix_1094887?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    char data;
    unordered_map<char, Node *> children;
    bool terminal;
    int freq;

    Node(char data){
        this->data = data;
        terminal = false;
        freq=0;
    }
};

class Trie{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }
    void insert(string w)
    {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            // agar value present h toh move kar uspar
            if (temp->children.count(ch))
            {
                temp->freq++;
                temp = temp->children[ch];
            }
            // warna new node create karke uspar jao
            else
            {
                Node *newNode = new Node(ch);
                temp->children[ch] = newNode;
                temp->freq++;
                temp = newNode;
            }
        }
        temp->terminal = true;
    }

 void sup(string str, string &ans){
        Node *temp = root;
         char ch = str[0];
        ans.push_back(ch);
          //root se letter par aayega jo already insert ho gaya
      temp = temp->children[ch];
     
    for(int i=1;i<str.size();i++){
        char ch=str[i];
        if(temp->freq==1){
            if(temp->terminal) ans.push_back(str[i]);
            return;
            
        }
            //aage badh jao
            temp=temp->children[ch];
            ans.push_back(str[i]);
    }
}

};
vector<string> shortestUniquePrefix(vector<string> s, int n) 
{
   Trie t;
    for (int i = 0; i < n; i++)    {
        t.insert(s[i]);
    }
    vector<string> ans;
    for(int i = 0; i<n; i++)
    {
        string result = "";
        t.sup(s[i], result);
        ans.push_back(result);
    }
    return ans;
}
