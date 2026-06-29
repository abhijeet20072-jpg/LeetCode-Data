class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>m;
        for(char x:s)m[x]++;
        int c=0;
        for(auto it:m){
            if(it.second%2)c++;
        }
        return c<=k&&k<=s.size();
    }
};