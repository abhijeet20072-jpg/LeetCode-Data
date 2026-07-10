class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,bool>m;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<y.size();i++){
            pq.push({y[i],i});
        }
        int s=0;
        while(!pq.empty()){
            auto it=pq.top();
            if(m[x[it.second]]==false){
                m[x[it.second]]=true;
                s+=it.first;
            }
            pq.pop();
            if(m.size()==3)return s;
        }
        return -1;
    }
};