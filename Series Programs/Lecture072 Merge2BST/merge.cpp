// codestudio ==> https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void storeInOrder(TreeNode<int> *root, vector<int> &arr) {
    if (root != NULL) {
        storeInOrder(root->left, arr);
        arr.push_back(root->data);
        storeInOrder(root->right, arr);
    }
}

// Function to merge two sorted array/lists.
vector<int> mergeSortedArrays(vector<int> &arr1, vector<int> &arr2) {
    int i = 0, j = 0;
    vector<int> arr;
    
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            arr.push_back(arr1[i]);
            i++;
        } else {
            arr.push_back(arr2[j]);
            j++;
        }
    }
    
    while (i < arr1.size()) {
        arr.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        arr.push_back(arr2[j]);
        j++;
    }
    
    return arr;
}

// Function to convert sorted array-list to balanced BST.
TreeNode<int> *constructBSTFromSortedArray(vector<int> &arr, int start, int end) {
    // Base case.
    if (start > end) return NULL;
        
    int mid = (start + end) / 2;
    
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = constructBSTFromSortedArray(arr, start, mid - 1);
    root->right = constructBSTFromSortedArray(arr, mid + 1, end);
    return root;
}

TreeNode<int> * mergeBST(TreeNode<int> *root1, TreeNode<int> *root2) {
    // Store the in-order traversal of tree1 in an array.
    vector<int> temp1;
    storeInOrder(root1, temp1);
    
    // Store the in-order traversal of tree2 in an array.
    vector<int> temp2;
    storeInOrder(root2, temp2);
    
    // Merge the two sorted arrays.
    vector<int> final = mergeSortedArrays(temp1, temp2);
    
    // Construct the balanced BST from this sorted array.
    return constructBSTFromSortedArray(final, 0, final.size() - 1);
}
