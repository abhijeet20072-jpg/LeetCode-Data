class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<multiset<char>,int>m;
        int i=-1;
        for(string s:strs){
            multiset<char>st;
            for(char c:s){
                st.insert(c);
            }
            if(m.find(st)==m.end()){
                i++;
                m[st]=i;
            }
        }
        vector<vector<string>>ans(i+1);
        for(string s:strs){
            multiset<char>st;
            for(char c:s){
                st.insert(c);
            }
            ans[m[st]].push_back(s);
        }
        return ans;
    }
};