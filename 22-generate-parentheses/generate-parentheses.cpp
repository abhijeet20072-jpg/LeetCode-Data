class Solution {
public:
    void f(vector<string>& ans,string& d,int n,int o,int c){
        if(o==n&&c==n){
            ans.push_back(d);
            return;
        }
        if(o<n){
            d+='(';
            f(ans,d,n,o+1,c);
            d.pop_back();
        }
        if(c<o){
            d+=')';
            f(ans,d,n,o,c+1);
            d.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string d;
        f(ans,d,n,0,0);
        return ans;
    }
};