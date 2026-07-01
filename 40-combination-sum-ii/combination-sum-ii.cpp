class Solution {
public:
    void f(vector<vector<int>>& ans,vector<int>& d,vector<int>& a,int idx,int t){
        int sum=0;
        for(int x:d)sum+=x;
       
           
        if(sum==t)ans.push_back(d);
        if(sum>t)return;
        
        for(int i=idx;i<a.size();i++){
        if(i>idx&&a[i]==a[i-1])continue;
        d.push_back(a[i]);   //take
        f(ans,d,a,i+1,t);
        d.pop_back();  
        }  //not take
    
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>d;
        f(ans,d,candidates,0,target);
        return ans;
    }
};