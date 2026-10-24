class Solution {
public:

    int steps(vector<int>& nums,int s,int e,vector<int>& dp){
        if(s>=e)return 0;
        if(dp[s]!=-1)return dp[s];
        int cnt=1e8;
        int x=nums[s];
        for(int i=1;i<=x&&s+i<=e;i++){
                cnt=min(cnt,1+steps(nums,s+i,e,dp));
        }
        return dp[s]=cnt;
    }



    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return steps(nums,0,nums.size()-1,dp);

    }
};