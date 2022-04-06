class Solution {
public:
    bool isSafe(vector<string> board, int row, int col){
        int rr = row;
        int cc = col;
        while(cc>=0){
            if(board[rr][cc]=='Q') return false;
            cc--;
        }
        rr = row, cc = col;
        while(cc>=0 && rr>=0){
            if(board[rr][cc] == 'Q') return false;
            rr--; cc--;
        }
        rr = row, cc = col;
        while(cc>=0 && rr<board.size()){
            if(board[rr][cc] == 'Q') return false;
            rr++; cc--;
        }
        return true;
    }
    void solve(int n, vector<vector<string>>& ans, vector<string>& board, int col){
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++){
            if(isSafe(board, row, col)) {
                board[row][col] = 'Q';
                solve(n, ans, board, col+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0; i<n; i++){
            board[i] = s;
        }
        solve(n, ans, board, 0);
        return ans;
    }
};