class Solution {
public:


    void fill(vector<vector<int>>& image, int sr, int sc, int color){
        int m=image.size();
        int n=image[0].size();

        if(sr<0||sr>=m||sc<0||sc>=n)return;
        int og=image[sr][sc];
        image[sr][sc]=color;
        if(sr+1<m&&image[sr+1][sc]==og){
            fill(image,sr+1,sc,color);
        }
        if(sr-1>=0&&image[sr-1][sc]==og){
            fill(image,sr-1,sc,color);
        }
        if(sc+1<n&&image[sr][sc+1]==og){
            fill(image,sr,sc+1,color);
        }
        if(sc-1>=0&&image[sr][sc-1]==og){
            fill(image,sr,sc-1,color);
        }

        

        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ogcolor=image[sr][sc];
        if(ogcolor!=color){
            fill(image,sr,sc,color);
        }
        return image;
    }
};