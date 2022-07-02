// also known as the n-ary tree or the generic tree

// T.C. : O(l) where l is the length of the string same for insertion and searching  
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};
class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string str)
    {
        // base case
        if (str.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assuming words are in lowercase
        int index = str[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absemt
            child = new TrieNode(str[0]);
            root->children[index] = child;
        }
        // recursion
        // aage wala pass kar diya pehle letter ko chodh kar
        insertUtil(child, str.substr(1));
    }

    void insertWord(string str)
    {
        if (root == NULL)
        {
            root = new TrieNode(' ');
        }
        insertUtil(root, str);
    }

    bool searchUtil(TrieNode *root, string str)
    {
        // base case
        if (str.length() == 0)
        {
            return root->isTerminal;
        }
        // assuming words are in lowercase
        int index = str[0] - 'a';
        TrieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }
        // recursion
        // aage wala pass kar diya pehle letter ko chodh kar
        return searchUtil(child, str.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

   
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("hello");
    t->insertWord("help");
    t->insertWord("hel");
    t->insertWord("arm");
    t->insertWord("army");
    cout<<"present or not : "<<t->search("hello")<<endl;
    cout<<"present or not : "<<t->search("armi")<<endl;

    return 0;   
}