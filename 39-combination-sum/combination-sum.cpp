class Solution {
public:
    void f(vector<vector<int>>& ans,vector<int>& d,vector<int>& a,int s,int t,int idx){
        if(s==t){
            ans.push_back(d);
            return;
        }
        for(int i=idx;i<a.size();i++){
            if(s+a[i]<=t){
            d.push_back(a[i]);
            f(ans,d,a,s+a[i],t,i);
            d.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>d;
        f(ans,d,candidates,0,target,0);
        return ans;
    }
};