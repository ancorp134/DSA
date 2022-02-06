// leetcode ==> https://leetcode.com/problems/binary-tree-level-order-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
       vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
           if(root==NULL) return ans;
           queue<TreeNode*> q;
           q.push(root);
           while(!q.empty()){
               int size=q.size();
               vector<int> level;
               for(int i=0; i<size;i++){
                   TreeNode* node=q.front();
                   q.pop();
                   if(node->left!=NULL) q.push(node->left);
                   if(node->right!=NULL) q.push(node->right);
                   level.push_back(node->val);
               }
               ans.push_back(level);
           }
        return ans;
    }
};

//2nd Approach --
// class Solution {
// public:
//      vector<vector<int>> res;
    
//      void rec(TreeNode* root, int level) {
//         if (!root) return;
//          // cout << "level =" << level << " size =" << res.size() ;
//         if (level == res.size()) res.push_back({});
//         res[level].push_back(root->val);
//          // cout << " Value =" << root->val <<endl; 
//         rec(root->left, level+1);
//         rec(root->right, level+1);
//     }
	
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         rec(root, 0);
//         return res;
//     }
// };
