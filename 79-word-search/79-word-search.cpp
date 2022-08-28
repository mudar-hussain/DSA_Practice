class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int ind){
        if(ind>= word.length())
            return true;
        
        if(i<0 || j<0 || i>=board.size() || j >= board[0].size() || board[i][j] != word[ind] || board[i][j] == '*')
            return false;
        
        board[i][j] = '*';
        
        bool down = dfs(board, word, i+1, j, ind+1);
        if(down)    return true;
        bool up = dfs(board, word, i-1, j, ind+1);
        if(up)    return true;
        bool right = dfs(board, word, i, j+1, ind+1);
        if(right)    return true;
        bool left = dfs(board, word, i, j-1, ind+1);
        if(left)    return true;
        
        board[i][j] = word[ind];
        
        return false;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        int freq[128] = {};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                freq[board[i][j]]++;
            }
        }
        for(auto ch: word){
            if(--freq[ch]<0)
                return false;
        }
        
        // vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};