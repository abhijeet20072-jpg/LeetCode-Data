class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)return{};
        vector<int>ans=arr;
        unordered_map<int,int>m;
        sort(ans.begin(),ans.end());
        int st=ans[0];
        m[st]=1;
        for(int i=1;i<ans.size();i++){
            if(ans[i]>st){
                m[ans[i]]=m[st]+1;
                st=ans[i];
            }
        
        }

        for(int i=0;i<arr.size();i++){
            ans[i]=m[arr[i]];
        }
        return ans;
    }
};