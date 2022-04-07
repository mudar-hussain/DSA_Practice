//2nd Approach ( BitMasking )

class Solution
{
private:
    int r[9];
    int c[9];
    int t[3][3];
    bool ans;
    vector<pair<int, int>> pos;

public:
    void fill(int i, int j, int n)
    {
        r[i] ^= 1 << n;
        c[j] ^= 1 << n;
        t[i / 3][j / 3] ^= 1 << n;
        return;
    }
    void init(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int n = board[i][j] - '1';
                    fill(i, j, n);
                }
            }
        }
        return;
    }
    void dfs(int idx, vector<vector<char>> &board)
    {
        if (idx == pos.size())
        {
            ans = true;
            return;
        }
        int a = pos[idx].first, b = pos[idx].second;
        int mask = ~(r[a] | c[b] | t[a / 3][b / 3]) & 0x1ff;
        for (; mask && !ans; mask &= mask - 1)
        {
            int choose = mask & -mask;
            int n = __builtin_ctz(choose);
            fill(a, b, n);
            board[a][b] = '1' + n;
            dfs(idx + 1, board);
            fill(a, b, n);
        }
        return;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        memset(t, 0, sizeof(t));
        init(board);
        ans = false;
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] == '.')
                    {
                        int mask = ~(r[i] | c[j] | t[i / 3][j / 3]) & 0x1ff;
                        if (!(mask - 1 & mask))
                        {
                            int n = __builtin_ctz(mask);
                            fill(i, j, n);
                            flag = true;
                            board[i][j] = '1' + n;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    pos.emplace_back(i, j);
                }
            }
        }
        dfs(0, board);
    }
};

//1st Approach ( Backtracking )
// class Solution {
// public:
//     bool isValid(vector<vector<char>> board, int i, int j, int c){
//         for(int k = 0; k<9; k++){
//             if(board[k][j] == c || board[i][k] == c) return false;
//             if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == c)
//                 return false;
//         }
//         return true;
        
        
//     }
//     bool solve(vector<vector<char>>& board){
//         for(int i = 0; i<9; i++){
//             for(int j = 0; j<9; j++){
//                 if(board[i][j] == '.'){
//                     for(int c = '1'; c <= '9'; c++){
//                         if(isValid(board, i, j, c)){
//                             board[i][j] = c;
//                             if(solve(board)) return true;
//                             else board[i][j] = '.';
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board);
//     }
// };