class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int ind, vector<vector<bool>>& vis){
        if(ind>= word.length())
            return true;
        
        if(i<0 || j<0 || i>=board.size() || j >= board[0].size() || board[i][j] != word[ind] || vis[i][j])
            return false;
        
        vis[i][j] = true;
        
        bool down = dfs(board, word, i+1, j, ind+1, vis);
        bool up = dfs(board, word, i-1, j, ind+1, vis);
        bool right = dfs(board, word, i, j+1, ind+1, vis);
        bool left = dfs(board, word, i, j-1, ind+1, vis);
        
        vis[i][j] = false;
        
        return up || down || right || left;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j, 0, vis))
                        return true;
                }
            }
        }
        return false;
    }
};