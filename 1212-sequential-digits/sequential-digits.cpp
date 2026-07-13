class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        long long rl=1e9;
        set<int>s;
        for(int i=1;i<=9;i++){
            long long a=i;
            int x=i;
            while(a<=rl&&x<9){
                x++;
                a=a*10+x;
                s.insert(a);
            }
        }
        vector<int>ans;
        for(auto it:s){
            ans.push_back(it);
        }
        int st,e;
        for(int i=0;i<ans.size();i++){
            if(ans[i]<low){
                continue;
            }
            else if(ans[i]==low){
                st=i;
                break;
            }
            else{
                st=i;
                break;
            }
        }

        for(int i=0;i<ans.size();i++){
            if(ans[i]<high){
                e=i;
            }
            else if(ans[i]==high){
                e=i;
                break;
            }
            else{
                break;
            }
        }
        if(high<12)return{};
      
        return vector<int>(ans.begin()+st,ans.begin()+e+1);
    }
};