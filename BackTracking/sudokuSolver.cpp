class Solution {
public:
    bool issafe(int row,int col,vector<vector<char>>& board,char ch,int n){
        int x=row,y=col;
        //checking the row and col and diagonal
        for(int i=0; i<n;i++){
            if(board[x][i]==ch) return false;
            if(board[i][y]==ch) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false;
        }
        return true;


    }


    bool solve(vector<vector<char>>& board,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    for(char ch='1'; ch<='9';ch++ ){
                        if(issafe(i,j,board,ch,n)){
                            board[i][j]=ch;
                            bool nextpossible=solve(board,n);  //recursion call
                            if(nextpossible) return true;
                            else board[i][j]='.'; //backtracked
                        }
                    }
                    return false;
                }

            }
        }
        return true;        
    }
    void solveSudoku(vector<vector<char>>& board) { 
        int n=board.size();
        bool ans=solve(board,n);
    }
};