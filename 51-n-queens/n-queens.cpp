class Solution {
public:
    bool check(vector<string>&d,int r,int c,int n){
        for(int i=0;i<n;i++){
            if(d[i][c]=='Q')return false;    //col check
        }
        for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--){
            if(d[i][j]=='Q')return false;
        }
        for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++){
            if(d[i][j]=='Q')return false;
        }
        return true;
    }
    void f(vector<vector<string>>& ans,vector<string>& d,int n,int r){
        if(r==n){
            ans.push_back(d);
            return;
        }
        for(int i=0;i<n;i++){
            if(check(d,r,i,n)){
                d[r][i]='Q';
                f(ans,d,n,r+1);
                d[r][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++)s+='.';
        vector<vector<string>>ans;
        vector<string>d(n,s);
        f(ans,d,n,0);
        return ans;
    }
};