class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&nums,vector<int>&d,vector<bool>& used){
        if(d.size()==nums.size()){
            ans.push_back(d);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==false){
                used[i]=true;
                d.push_back(nums[i]);
                solve(ans,nums,d,used);
                d.pop_back();
                used[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>d;
        vector<bool>used(nums.size(),false);
        solve(ans,nums,d,used);
        return ans;
    }
};