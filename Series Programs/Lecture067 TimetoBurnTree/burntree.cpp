// geeksForgeeks ==> https://practice.geeksforgeeks.org/problems/burning-tree/1

class Solution {
  public:
    Node* createParentMapping(Node* root, int target, map<Node*,Node*>&nodeToParent){
      
      queue<Node*>q;
      Node* res=NULL;
      q.push(root);
      nodeToParent[root]=NULL;
      
      while(!q.empty()){
          Node* top=q.front();
          q.pop();
          
          if(top->data==target){
              res=top;
          }
          
          if(top->left){
              nodeToParent[top->left]=top;
              q.push(top->left);
          }
           if(top->right){
              nodeToParent[top->right]=top;
              q.push(top->right);
          }
      }
      return res;
  }
   int burnTree(Node* root,map<Node*,Node*>&nodeToParent){
      map<Node*,int>visited;
      queue<Node*>q;
      //to check addn of timer
     int ans=0;
      q.push(root);
      visited[root]=true;
      
      while(!q.empty()){
          bool flag=0;
          int size=q.size();
          for(int i=0;i<size;i++){
              //process the neighbouring nodes
              Node* top=q.front();
              q.pop();
              
              //3 way to burn in 1s--left,right,top
              if(top->left && !visited[top->left]){
                  flag=1;
                  q.push(top->left);
                  visited[top->left]=true;
              }
              if(top->right && !visited[top->right]){
                  flag=1;
                  q.push(top->right);
                  visited[top->right]=true;
              }
              //checking parent node in map
              if(nodeToParent[top] && !visited[nodeToParent[top]]){
                  flag=1;
                  q.push(nodeToParent[top]);
                  visited[nodeToParent[top]]=true;
              }
          }
          if(flag==1)   ans++;
      }
      return ans;
  }
  //DRIVER FUNCTION
    int minTime(Node* root, int target) 
    {
        //algo:
        //step1- create parent mapping
        //step2- find the target node
        //step3-burn the tree in min time
       
        map<Node*,Node*>nodeToParent;
        Node* targetNode=createParentMapping(root,target,nodeToParent);
        int ans=burnTree(targetNode,nodeToParent);
        
        //timer--min
        return ans;
        
    }
  
};
