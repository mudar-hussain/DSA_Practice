class Solution {
public:
    int dir[5] = {-1,0,1,0,-1};
    int r,c;
    void dfs(vector<vector<int>>& image, int sr, int sc, int base, int &color){
        if(image[sr][sc] != base) return;
        
        image[sr][sc] = color;
        
        for(int k = 0; k<4; k++){
            r = sr+dir[k];
            c = sc+dir[k+1];
            if(r>=0 && c>=0 && r<image.size() && c<image[0].size())
                dfs(image, r, c, base, color);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)
            dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};