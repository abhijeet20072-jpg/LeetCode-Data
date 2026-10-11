class Solution {
public:
    int paths(int m,int n,int x,int y,vector<vector<int>>& dp){
        if(x==m-1&&y==n-1){
            return 1;
        }
        if(dp[x][y]!=-1)return dp[x][y];
            int a=0;
            if(y<n-1){
            y++;
            a=a+paths(m,n,x,y,dp);
            y--;
            }
            if(x<m-1){
            x++;
            a=a+paths(m,n,x,y,dp);
            x--;
            }
            return dp[x][y]=a;
    }
    int uniquePaths(int m, int n) {
       vector<vector<int>>dp(m,vector<int>(n,-1));
        int path=paths(m,n,0,0,dp);
        return path;
    }
};