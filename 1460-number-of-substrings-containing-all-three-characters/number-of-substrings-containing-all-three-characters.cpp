class Solution {
public:
    void no(string& s,vector<int>& c,int x){
       int lc=-1;
       for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='a'+x)lc=i;
        c[i]=lc;
       }
       return;
    }
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int>a(n);
        vector<int>b(n);
        vector<int>c(n);
        no(s,a,0);
        no(s,b,1);
        no(s,c,2);
        int ans=0;
        for(int i=0;i<s.size()-2;i++){
            if(a[i]!=-1&&b[i]!=-1&&c[i]!=-1){
                ans+=(n-max(a[i],max(b[i],c[i])));
            }
        }
        return ans;
    }
};