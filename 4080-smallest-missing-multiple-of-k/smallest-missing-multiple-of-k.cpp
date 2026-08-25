class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int x:nums)m[x]++;
        int c=1,y=k;
        while(1){
            if(!m[k])return k;
            c++;
            k=y*c;
        }
        return -1;
    }
};