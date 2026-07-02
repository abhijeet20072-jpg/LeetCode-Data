class Solution {
public:
    void f(vector<vector<int>>& ans,vector<int>& d,int idx,int n,int k){
        if(d.size()==k){
            if(n==0)ans.push_back(d);     //base case
            return;
        }
        for(int i=idx;i<10;i++){
            if(i>n)break;
            if(n-i>=0){
                d.push_back(i);     //make choice
                f(ans,d,i+1,n-i,k);         // make all states
                d.pop_back();        // undo choice
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>a;
        vector<vector<int>>ans;
        f(ans,a,1,n,k);
        return ans;
    }
};