class Solution {
public:


    // int f(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>& dp){
    //     if(row==matrix.size()-1){
    //         return matrix[row][col];
    //     }
    //     if(dp[row][col]!=-1)return dp[row][col];
    //     int left=INT_MAX,right=INT_MAX;

    //     if(col>0){
    //         left=matrix[row][col]+f(row+1,col-1,matrix,dp);
    //     }
    //     if(col<matrix.size()-1){
    //         right=matrix[row][col]+f(row+1,col+1,matrix,dp);
    //     }
    //     int down=matrix[row][col]+f(row+1,col,matrix,dp);
    //     return dp[row][col]=min(left,min(right,down));
    // }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<n;i++){
            
            for(int j=0;j<n;j++){
                int left=INT_MAX,right=INT_MAX;
                int down=matrix[i][j]+dp[i-1][j];
                if(j>0){
                    left=matrix[i][j]+dp[i-1][j-1];
                }
                if(j<n-1){
                    right=matrix[i][j]+dp[i-1][j+1];
                }

                dp[i][j]=min(down,min(right,left));
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};