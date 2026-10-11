class Solution {
public:

    int paths(vector<vector<int>>& obstacleGrid,int m,int n,vector<vector<int>>& dp){
        
        
        if(m<0||n<0)return 0;

        if(obstacleGrid[m][n]==1)return 0;

        if(m==0&&n==0)return 1;
        if(dp[m][n]!=-1)return dp[m][n];
        int a=paths(obstacleGrid,m-1,n,dp);
       int b=paths(obstacleGrid,m,n-1,dp);
        return dp[m][n]=a+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return paths(obstacleGrid,m-1,n-1,dp);

    }
};