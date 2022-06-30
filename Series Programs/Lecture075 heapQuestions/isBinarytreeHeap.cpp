// https://www.codingninjas.com/codestudio/problems/is-binary-heap-tree_893136?leftPanelTab=0

//   Time complexity: O(N)    Space complexity: O(N)

bool isBinaryHeapTree(BinaryTreeNode<int>* root){
    // List to store 'node, position'.
    vector<pair<BinaryTreeNode<int>*, int>> nodeArr;
    nodeArr.push_back(make_pair(root, 1));
    int i = 0;

    while (i < nodeArr.size()){
        BinaryTreeNode<int>* node = nodeArr[i].first;
        int position = nodeArr[i].second;
        i += 1;

        // If left child is not 'None'.
        if (node->left){
            // Append left child.
            nodeArr.push_back(make_pair(node->left, 2 * position));
// Condition to check, Is value of parent node is greater than it's left child.
            if (node->left->data > node->data) return false;
       }

        // If right child is not 'None'.
        if (node->right){
            // Append right child.
            nodeArr.push_back(make_pair(node->right, 2 * position + 1));
            if (node->right->data > node->data)    return false;
        }
    }

    int lastIndex = nodeArr.size() - 1;
    return nodeArr[lastIndex].second == nodeArr.size();
}