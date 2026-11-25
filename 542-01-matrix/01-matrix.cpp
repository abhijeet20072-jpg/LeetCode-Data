class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m=mat.size(),n=mat[0].size();

        vector<vector<int>>distance(m,vector<int>(n,0));
        vector<vector<int>>visited(m,vector<int>(n,-1));
        queue<pair<int,pair<int,int>>>q;



        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0&&visited[i][j]==-1){
                    visited[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()){
            auto  it=q.front();
            q.pop();
            int dis=it.first;
            int x=it.second.first;
            int y=it.second.second;


            if(x-1>=0&&visited[x-1][y]==-1){
                if(mat[x-1][y]==1){
                    distance[x-1][y]=dis+1;
                }
                q.push({dis+1,{x-1,y}});

                visited[x-1][y]=1;
            }

            if(x+1<m&&visited[x+1][y]==-1){
                if(mat[x+1][y]==1){
                    distance[x+1][y]=dis+1;
                }
                q.push({dis+1,{x+1,y}});

                visited[x+1][y]=1;
            }

            if(y-1>=0&&visited[x][y-1]==-1){
                if(mat[x][y-1]==1){
                    distance[x][y-1]=dis+1;
                }
                q.push({dis+1,{x,y-1}});


                visited[x][y-1]=1;
            }

            if(y+1<n&&visited[x][y+1]==-1){
                if(mat[x][y+1]==1){
                    distance[x][y+1]=dis+1;
                }
                q.push({dis+1,{x,y+1}});


                visited[x][y+1]=1;
            }

            
        }


        return distance;

    }
};