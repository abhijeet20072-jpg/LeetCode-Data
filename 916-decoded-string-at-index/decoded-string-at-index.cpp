class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        for(char c : s){
            if(c>='a' && c<='z') len++;
            else{
                len *= (c - '0');
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>='0' && s[i]<='9'){
                len /= (s[i]-'0');
                k%=len;
            }
            else{
                if(k==0 || k==len){
                    return string(1,s[i]);
                }
                len--;
            }
        }
        return "";
    }
};