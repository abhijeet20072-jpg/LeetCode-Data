class Solution {
public:
    bool check(vector<string>& d,int r,int n,int c){
        for(int i=0;i<n;i++){
            if(d[i][c]=='Q')return false;
        }
        for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--){
            if(d[i][j]=='Q')return false;
        }
        for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++){
            if(d[i][j]=='Q')return false;
        }
        return true;
    }

    void f(int& ans,vector<string>& d,int r,int n){
        if(r==n){
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(check(d,r,n,i)){
                d[r][i]='Q';
                f(ans,d,r+1,n);
                d[r][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++)s+='.';
        vector<string>d(n,s);
        int ans=0;
        f(ans,d,0,n);
        return ans;
    }
};