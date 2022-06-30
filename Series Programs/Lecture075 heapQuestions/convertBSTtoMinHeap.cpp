// codestudio ==> https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498?leftPanelTab=1

/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
priority_queue <int, vector <int>, greater<int> > p;
 void pre (BinaryTreeNode* root){
      if (!root) return;
     p.push(root->data);
     pre (root->left);
     pre (root->right);
 }

  void create (BinaryTreeNode* root){
       if (!root) return;
       root->data= p.top(); p.pop();
       create (root->left);
       create (root->right);
  }

BinaryTreeNode* convertBST(BinaryTreeNode* root){
    // Write your code here.
    pre(root);     
    create (root);
    return root;
}