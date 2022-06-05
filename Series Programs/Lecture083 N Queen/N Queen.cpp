// leetcode => https://leetcode.com/problems/n-queens/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:    
    vector<vector<string>>ans;
    //this simply checks if the queen can be placed in the given row or not
    bool isSafeToPlaceQueen(vector<string>&board,int row,int col,int n){
        //checking whether a queen already exists in same col
        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q')return false;
            }
        //checking left diagonal
        int x = row-1;
        int y = col-1;
        while(x>=0 && y>=0){
            if(board[x][y] == 'Q')return false;
            x--;
            y--;
        } 
        //checking right diagonal
        x = row-1;
        y = col+1;
        while(x>=0 && y<n){
            if(board[x][y] == 'Q')return false;
            x--;
            y++;
        }
        return true;
    }
//this function will place the queen in the board
    void nQueens(vector<string>&curr,int n,int row){        
        if(row == n){
            ans.push_back(curr);
            return;
        }        
        for(int col=0;col<n;col++){
            if(isSafeToPlaceQueen(curr,row,col,n)){
                curr[row][col] = 'Q';
                nQueens(curr,n,row+1);
                curr[row][col] = '.';
            }
        }        
    }
  //DRIVER FUNCTION 
    vector<vector<string>> solveNQueens(int n) {        
       //["...." , "...." , "...." , "...."]
        vector<string> currRes(n,string(n,'.'));
        nQueens(currRes,n,0); //Recursive Function               
        return ans;
    }
};