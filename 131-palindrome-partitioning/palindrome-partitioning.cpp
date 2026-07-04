class Solution {
public:
    bool check(string& temp){
        for(int i=0,j=temp.size()-1;i<j;i++,j--){
            if(temp[i]!=temp[j])return false;
        }
        return true;
    }
    void part(vector<vector<string>>& ans,vector<string>&a,string& s,int idx){
        if(idx==s.size()){
            ans.push_back(a);
            return;
        }

        for(int i=idx;i<s.size();i++){
            string temp=s.substr(idx,i-idx+1);
            // for(int j=idx;j<=i;j++)temp+=s[j];
            if(check(temp)){
                a.push_back(temp);
                part(ans,a,s,i+1);
                a.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>a;
        part(ans,a,s,0);
        return ans;
    }
};