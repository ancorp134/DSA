// this method to solve this problem is not very efficient as the other solution can be done in S.c= O(1) and in same time
// it is used just to see the use case of the TRiE data structure.

// codestudio ==> https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// T.c ==> O(n*m)
// S.c ==> O(n*m)
#include <bits/stdc++.h>
using namespace std;
// program to implement trie data structure
class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
    bool terminal;
    int freq;

    Node(char data)
    {
        this->data = data;
        terminal = false;
        freq = 0;
    }
};

class Trie
{
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

    void lcp(string str, string &ans)
    {
        Node *temp = root;

        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if (temp->freq == 1)
            {
                ans.push_back(ch);
                // aage badh jao
                temp = temp->children[ch];
            }
            else
                break;
            if (temp->terminal)
                break;
        }
    }
};

string longestCommonPrefix(vector<string> &words, int n)
{
    Trie t;
    for (int i = 0; i < n; i++)
    {
        t.insert(words[i]);
    }
    string first = words[0];
    string ans = "";

    t.lcp(first, ans);
    return ans;
}