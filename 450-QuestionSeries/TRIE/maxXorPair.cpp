// codestudio ==> https://www.codingninjas.com/codestudio/problems/maximum-xor_3119012
// Time Complexity: O(N*32) + O(M*32)
// Space Complexity: O(N*32)
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;  // 0
    Node *right; // 1
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }
    // INSERT FUNCTION
    // 5= 0000101 32 Bit Integer
    void insert(int n)
    {

        Node *temp = root;
        // LOOP FROM MSB TO LSB
        for (int i = 31; i >= 0; i--)
        {
            int currentBit = (n >> i) & 1;

            if (currentBit == 0)
            {
                if (temp->left==NULL)
                    temp->left = new Node();
                temp = temp->left;
            }
            // currentBit=1
            else
            {
                if (temp->right==NULL)
                    temp->right = new Node();
                temp = temp->right;
            }
        }
    }
    // HELPER FUNCTION TO FIND MAX XOR PAIR
    // O(1) loop
    int helper(int val)
    {
        int ans = 0;
        Node *temp = root;

        // 0 -> move right; else vice versa
        for (int i = 31; i >= 0; i--)
        {
            int currentBit = (val >> i) & 1;

            if (currentBit==0)
            {                // FIND A complementary value to get 1 in the XOR
                if (temp->right!=NULL)  //as right=1
                {
                    temp = temp->right;
                    ans += (1 << i);
                }
                else
                    temp = temp->left;
            }
            else
            { //currentBit is 1
               // FIND A complementary value to get 1 in the XOR
                if (temp->left)
                {
                    temp = temp->left;
                    ans += (1 << i);
                }
                else
                    temp = temp->right;
            }
        }

        return ans;
    }

//THIS IS THE MAIN DRIVER FUNCTION
    // O(n)
    int findMaximumXOR(vector<int> &arr)
    {
        int n = arr.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {

            int value = arr[i];
            insert(value);

            int curAns = helper(value);

            res = max(curAns, res);
        }

        return res;
    }
};

int main()
{
    int arr[] = {14, 70, 53, 33, 49, 91, 36, 80, 92, 51, 66, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    Trie s;

    vector<int> v(arr, arr + n);
    cout << s.findMaximumXOR(v);

    return 0;
}