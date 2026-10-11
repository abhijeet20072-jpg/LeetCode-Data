class Solution {
public:

    int sum(int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp){

        if(m<0||n<0)return INT_MAX;
        if(m==0&&n==0)return grid[m][n];
        if(dp[m][n]!=-1)return dp[m][n];


        int a=sum(m-1,n,grid,dp);
        int b=sum(m,n-1,grid,dp);

        return dp[m][n]=grid[m][n]+min(a,b);
    }




    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return sum(m-1,n-1,grid,dp);
    }
};