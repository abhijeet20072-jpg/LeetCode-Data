class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        set<int>s;
        unordered_map<int,int>m;
        for(int i=0;i<=nums.size()-k;i++){
            for(int j=i;j<i+k;j++){
                s.insert(nums[j]);
            }
            for(int x:s){
                m[x]++;
            }
            s.clear();
        }
       int ans=-1;
        for(auto& it:m){
            if(it.second==1){
                if(it.first>ans)ans=it.first;
            }
        }
        return ans;
    }
};