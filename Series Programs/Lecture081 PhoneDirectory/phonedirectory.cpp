https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=3&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//using Trie 
class Node{
	public:
	char data;
	Node* child[26];
	bool isterminal;
	Node(char value){
		data = value;
		for(int i=0;i<26;i++){
			child[i]=NULL;
		}
		isterminal = false;
	}
};
class Trie{
	public:
	Node* root;
	Trie(){
		root = new Node('\0');
	}
	void insertutil(Node* root,string s){
		if(s.size()==0){
			root->isterminal = true;
			return ;
		}
		int ind = s[0]-'a';
		if(root->child[ind]==NULL){
			Node* node = new Node(s[0]);
			root->child[ind]=node;
		}
		root = root->child[ind];
		insertutil(root,s.substr(1));
	}
	void insert(string s){
		insertutil(root,s);
	}
	void directoryutil(Node* root,vector<string>& ans,string s){
		if(root->isterminal){
			ans.push_back(s);
		}
		for(int i=0;i<26;i++){
			if(root->child[i]!=NULL){
				s.push_back(root->child[i]->data);
				directoryutil(root->child[i],ans,s);
				s.pop_back();
			}
		}
	}
	vector<vector<string>> directory(string pre){
		vector<vector<string>> v;
		vector<string> ans;
		Node* head = root;
		int i=0;
		while(i<pre.size()){
			int ind = pre[i]-'a';
			head=head->child[ind];
			if(head==NULL){
				break;
			}
			i++;
			directoryutil(head,ans,pre.substr(0,i));
			v.push_back(ans);
			ans.resize(0);
		}
		return v;
	}
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
	Trie t;
	for(int i=0;i<contactList.size();i++){
		t.insert(contactList[i]);
	}
	return t.directory(queryStr);
}