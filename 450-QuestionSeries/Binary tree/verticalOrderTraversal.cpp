#include <bits/stdc++.h>
using namespace std;

int verticalOrder(TreeNode *root, int distance, map<int, vector<int>> &m)
{
    if (root == NULL)
        return 0;
    m[distance].push_back(root->val);
    int left = verticalOrder(root->left, distance - 1, m);
    int right = verticalOrder(root->right, distance + 1, m);
    return;
}

in