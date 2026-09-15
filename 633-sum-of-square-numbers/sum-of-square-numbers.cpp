class Solution {
public:
    bool judgeSquareSum(int c) {
        float a=pow(c,0.5);
        int b=(int)a;
        if(b*b==c)return true;
        int s=0,h=b;
        while(s<=h){
            if(pow(s,2)+pow(h,2)==c)return true;
            if(pow(s,2)+pow(h,2)>c){
                while(pow(s,2)+pow(h,2)>c)h--;
            }
            if(pow(s,2)+pow(h,2)<c){
                while(pow(s,2)+pow(h,2)<c)s++;
            }
        }
        return false;
    }
};