class Solution {
public:
     void solve(vector<vector<int>>&ans,vector<int>& nums,vector<int>& d,vector<bool>used){
            if(d.size()==nums.size()){
                ans.push_back(d);
                return;
            }

            for(int i=0;i<nums.size();i++){
                if(i>0&&nums[i]==nums[i-1]&&!used[i-1])continue;
                if(!used[i]){
                    used[i]=true;
                    d.push_back(nums[i]);
                    solve(ans,nums,d,used);
                    d.pop_back();
                    used[i]=false;
                }
            }
     }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<bool>used(nums.size(),false);
        vector<int>d;
        solve(ans,nums,d,used);
        return ans;
    }
};