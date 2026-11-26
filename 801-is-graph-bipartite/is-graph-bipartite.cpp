class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool flag=true;
        int n=graph.size();
        vector<int>coloured(n,-1);

        queue<pair<int,int>>q;



        for(int i=0;i<n;i++){

        if(coloured[i]!=-1)continue;

        q.push({i,0});

        coloured[i]=0;

        while(!q.empty()){
            int color=q.front().second;
            int val=q.front().first;

            q.pop();

            for(int x: graph[val]){
                if(coloured[x]==-1){
                    coloured[x]=1-color;
                    q.push({x,coloured[x]});
                }
                else{
                    if(coloured[x]==color){
                        flag=false;
                        break;
                    }
                }
            }

            if(!flag)break;
        }
        
        }

        return flag;

    }
};