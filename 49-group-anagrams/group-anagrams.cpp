class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
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
                ans.push_back({s});
            }
            else{
                ans[m[st]].push_back(s);
            }
        }
        return ans;
    }
};