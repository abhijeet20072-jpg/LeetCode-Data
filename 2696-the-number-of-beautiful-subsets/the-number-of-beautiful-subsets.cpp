class Solution {
public:
    void subset(vector<vector<int>>& ans,vector<int>& d,int idx,vector<int>& nums){
        if(idx==nums.size()){
           if(d.size()!=0) ans.push_back(d);
            return;
        }
        d.push_back(nums[idx]);
        subset(ans,d,idx+1,nums);
        d.pop_back();
        subset(ans,d,idx+1,nums);
    }
    bool check(vector<int>& a,int k){
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                if(abs(a[j]-a[i])==k)return false;
            }
        }
        return true;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>d;
        subset(ans,d,0,nums);
        int c=0;
        for(int i=0;i<ans.size();i++){
            if(check(ans[i],k))c++;
        }
        return c;
    }
};