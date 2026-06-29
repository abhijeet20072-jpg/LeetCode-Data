class Solution {
public:
   
    int numOfStrings(vector<string>& patterns, string word) {
        int c=0;
       unordered_map<string,int>m;
        for(int i=0;i<word.size();i++){
            string s="";
            for(int j=i;j<word.size();j++){
                s+=word[j];
                m[s]++;
            }
        }
        for(string s:patterns){
            if(m[s])c++;
        }
        return c;
    }
};