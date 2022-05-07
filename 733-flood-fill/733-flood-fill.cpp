class Solution {
    int target;
public:
    //2nd Approach (BFS)
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        int n=image[0].size();
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int oldColor=image[sr][sc];
        if(image[sr][sc]==newColor){
            return image;
        }
        image[sr][sc]=newColor;
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int newx=x+dir[k][0];
                int newy=y+dir[k][1];
                
                if(newx>=0 && newy>=0 && newx<m && newy<n && image[newx][newy]==oldColor){
                    q.push({newx,newy});
                    image[newx][newy]=newColor;
                }
            }
        }
        return image;
    }
    
    //1st Approach (DFS)
//     void reColor(vector<vector<int>>& image, int sr, int sc, int newColor){
//         if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != target || image[sr][sc] == newColor)
//             return;
        
//         image[sr][sc] = newColor;
//         reColor(image, sr-1, sc, newColor);
//         reColor(image, sr, sc-1, newColor);
//         reColor(image, sr, sc+1, newColor);
//         reColor(image, sr+1, sc, newColor);
        
//     }
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//         target = image[sr][sc];
//         if(target == newColor) 
//             return image;
        
//         reColor(image, sr, sc, newColor);
        
//         return image;
//     }
};