class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int x:nums){
            m[x]++;
        }
        vector<pair<int,int>>v;
        for(auto it : m){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        vector<int>a;
        for(int i=0;i<k;i++){
            a.push_back(v[i].second);
        }
        return a;
    }
};