class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0;
        int p=1;
        int x=n;
        while(n){
            s+=(n%10);
            p*=(n%10);
            n/=10;
        }
        s+=p;
        x%=s;
        return x==0;
    }
};