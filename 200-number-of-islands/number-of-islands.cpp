class Solution {
public:



    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visited){
            int m=grid.size();
            int n=grid[0].size();

            int x=i;
            int y=j;

            if(x<0||x>=m||y<0||y>=n)return;
       
            if(x-1>=0&&visited[x-1][y]==-1&&grid[x-1][y]=='1'){
                visited[x-1][y]=1;
                dfs(x-1,y,grid,visited);
            }
             if(y-1>=0&&visited[x][y-1]==-1&&grid[x][y-1]=='1'){
                visited[x][y-1]=1;
                dfs(x,y-1,grid,visited);
            }
             if(x+1<m&&visited[x+1][y]==-1&&grid[x+1][y]=='1'){
                visited[x+1][y]=1;
                dfs(x+1,y,grid,visited);
            }
             if(y+1<n&&visited[x][y+1]==-1&&grid[x][y+1]=='1'){
                visited[x][y+1]=1;
                dfs(x,y+1,grid,visited);
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
                    dfs(i,j,grid,visited);
                }
            }
        }
      
       return cnt;
    }
};