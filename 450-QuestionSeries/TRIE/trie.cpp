// codestudio ==> https://www.codingninjas.com/codestudio/problems/implement-trie_631356?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// also known as the generic tree or the n-ary tree
#include <bits/stdc++.h>
using namespace std;

// program to implement trie data structure
class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
    bool terminal;

    Node(char data)
    {
        this->data = data;
        terminal = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie(){
        root = new Node('\0');
    }
    void insert(char *w)
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
                temp = newNode;
            }
        }
        temp->terminal = true;
    }

    bool find(char *w)
    {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                return false;
            }
        }
        return temp->terminal;
    }

     /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         Node *temp = root;
        for (int i = 0; prefix[i] != '\0'; i++)
        {
            char ch = prefix[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                return false;
            }
        }
            return true;
    }
};

int main()
{
    Trie t;
    char words[][10] = {"the", "a", "there", "anaswer", "any", "by", "their"};
    char w[10];
    cin >> w;
    for (int i = 0; i < 7; i++)
    {
        t.insert(words[i]);
    }
    if (t.find(w))
    {
        cout << "present";
    }
    else
    {
        cout << "not present";
    }
}