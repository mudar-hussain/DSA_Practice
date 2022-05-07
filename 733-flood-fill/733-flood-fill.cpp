class Solution {
    int target;
public:
    void reColor(vector<vector<int>>& image, int sr, int sc, int newColor){
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != target || image[sr][sc] == newColor)
            return;
        
        image[sr][sc] = newColor;
        reColor(image, sr-1, sc, newColor);
        reColor(image, sr, sc-1, newColor);
        reColor(image, sr, sc+1, newColor);
        reColor(image, sr+1, sc, newColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        target = image[sr][sc];
        if(target == newColor) 
            return image;
        
        reColor(image, sr, sc, newColor);
        
        return image;
    }
};