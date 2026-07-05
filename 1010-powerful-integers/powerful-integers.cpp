class Solution {
public:
   
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_map<int,bool>m;
        long long p;
        if(bound<2)return{};
        if(x==1&&y==1)return{2};

        if(x==1&&y!=1){
            for(int j=0;j<=bound;j++){
                if((1+pow(y,j))<=bound){
                    m[1+pow(y,j)]=true;
                }
            }
        }
        else if(y==1&&x!=1){
            for(int j=0;j<=bound;j++){
                if((1+pow(x,j))<=bound){
                    m[1+pow(x,j)]=true;
                }
            }
        }

    else{
        for(int i=0;i<=bound;i++){
            if(pow(x,i)>=bound)break;
            for(int j=0;j<=bound;j++){
                p=pow(x,i)+pow(y,j);
                if(p<=bound)m[p]=true;
                else break;
            }
        }

}
        vector<int>a;
        for(int i=2;i<=bound;i++){
            if(m[i])a.push_back(i);
        }
        return a;
    }
};