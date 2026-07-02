class Solution {
public:
    bool found=false;
    bool check(vector<vector<char>>& board,int row,int col,char k){
        for(int j=0;j<9;j++)if(board[row][j]==k)return false;
        for(int i=0;i<9;i++)if(board[i][col]==k)return false;
        int x=row/3,y=col/3;
        for(int i=3*x;i<3*(x+1);i++){
            for(int j=3*y;j<3*(y+1);j++){
                if(board[i][j]==k)return false;
            }
        }
        return true;
    }
    void solve(vector<vector<char>>& board,int row,int col){
        if(row==9&&col==0){
            found=true;
            return;
        }
        
        if(board[row][col]=='.'){
        for(char k='1';k<='9';k++){
            if(check(board,row,col,k)){
                board[row][col]=k;
                if(col==8){solve(board,row+1,0);}
                else{solve(board,row,col+1);}
                if(found)break;
                board[row][col]='.';
                }
            }
        }

        else{
            if(col==8){solve(board,row+1,0);}
            else{solve(board,row,col+1);}
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        return;
    }
};