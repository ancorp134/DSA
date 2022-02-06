#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* buildTree(){
    int d;
    cin >> d;
    if(d == -1)
        return NULL;

    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

//ROOT LEFT RIGHT
void printPreOrder(Node* root){
    if(root == NULL)
        return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

//LEFT ROOT RIGHT
void printInOrder(Node* root){
    if(root ==NULL)
    return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

//LEFT RIGHT ROOT
void printPostOrder(Node* root){
    if(root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

//FUNCTION TO CALCULATE THE HEIGHT OF THE TREE
int height(Node* root){
    if(root == NULL)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight) + 1;
}

//mirror of the tree
void mirror(Node* root){
    if(root == NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}
//function to print level order traversal of binary tree
void printLevelOrder(Node* root){
    int h = height(root);
    for(int i = 1; i <= h; i++){
        printGivenLevel(root, i);
        cout << endl;
    }
}

void printGivenLevel(Node* root, int level){
    if(root == NULL)
        return;
    if(level == 1){
        cout << root->data << " ";
        return;
    }
    printGivenLevel(root->left, level - 1);
    printGivenLevel(root->right, level - 1);
}

int main(){
    Node *root = buildTree();
    printPreOrder(root);
    cout << endl;
    printInOrder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    cout << "Height of the tree is " << height(root);
    cout << endl;
    printLevelOrder(root);
    return 0;
}