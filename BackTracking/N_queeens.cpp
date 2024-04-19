class Solution {
public:
    void addSolution(vector<vector<string>> &ans,vector<vector<char>> &board,int n){
        vector<string> output;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s=s+board[i][j];
            }
            output.push_back(s);
        }
        ans.push_back(output);

    }

    bool isSafe(int row,int col,vector<vector<char>> &board,int n){
        
        //row checking
        // for(int i=0;i<n;i++){
        //      if(board[row][i]=='Q'){
        //         isrow=false;
        //         breakl
        //      }
        // }
        //col checking

        //upar wale check karo as top to down fill kar rhe hain
        int x=row,y=col;
        while(x>=0){
            if(board[x][y]=='Q') return false;
            x--;
        }
        //diagonal checking  
        //above right diagonal
        x=row,y=col;
        while(x>=0 && y>=0){
            if(board[x][y]=='Q') return false;
            x--;
            y--;
        }

        //above left diagonal
        x=row,y=col;
        while(x>=0 && y<n){
            if(board[x][y]=='Q') return false;
            x--;
            y++;
        }

        return true;

    }


    void solve(int row,vector<vector<string>> &ans,vector<vector<char>> &board,int n){
        if(row==n){
            addSolution(ans,board,n);
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(row+1,ans,board,n);
                //backtrack
                board[row][col]='.';
            }
        }

    }

     
    vector<vector<string>> solveNQueens(int n) {
        vector <vector<char>>board(n,vector<char>(n,'.'));
        vector<vector< string >> ans;
        solve(0,ans,board,n);
        return ans;
    }
};