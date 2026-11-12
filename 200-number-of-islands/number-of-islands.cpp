class Solution {
public:



    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visited){

        queue<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        visited[i][j]=1;

        q.push({i,j});

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;

            q.pop();
            if(x-1>=0&&visited[x-1][y]==-1&&grid[x-1][y]=='1'){
                visited[x-1][y]=1;
                q.push({x-1,y});
            }
             if(y-1>=0&&visited[x][y-1]==-1&&grid[x][y-1]=='1'){
                visited[x][y-1]=1;
                q.push({x,y-1});
            }
             if(x+1<m&&visited[x+1][y]==-1&&grid[x+1][y]=='1'){
                visited[x+1][y]=1;
                q.push({x+1,y});
            }
             if(y+1<n&&visited[x][y+1]==-1&&grid[x][y+1]=='1'){
                visited[x][y+1]=1;
                q.push({x,y+1});
            }
        }


    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>visited(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==-1&&grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid,visited);
                }
            }
        }
      
       return cnt;
    }
};