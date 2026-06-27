class Solution {
public:
    bool check(string& a){
        int c=0;
        for(int i=1;i<a.size();i++){
            if(a[i]==a[i-1])c++;
        }
        return c<=1;
    }
    int longestSemiRepetitiveSubstring(string s) {
        int ans=1;
        int n=s.size();
        for(int i=0;i<n;i++){
            string a="";
            for(int j=i;j<n;j++){
                a+=s[j];
                if(check(a)){
                    ans=max(ans,(j-i+1));
                }
            }
        }
        return ans;
    }
};