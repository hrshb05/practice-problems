class Solution {
public:
  int mod = 1e9+7;
    int dp[52][52][52];
    int helper(int i, int j, int m, int n, int maxMove, int moves)
    {
        if(i >= m || j >= n || j < 0 || i < 0) return 1;
        if(moves == maxMove) return 0;
        if(dp[moves][i][j] != -1) return dp[moves][i][j] % mod;
        int ans = 0;
        ans = (ans + helper(i+1, j, m, n, maxMove, moves + 1)) % mod;
        ans = (ans + helper(i-1, j, m, n, maxMove, moves + 1)) % mod;
        ans = (ans + helper(i, j+1, m, n, maxMove, moves + 1)) % mod;
        ans = (ans + helper(i, j-1, m, n, maxMove, moves + 1)) % mod;
        dp[moves][i][j] = ans % mod;
        return dp[moves][i][j];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return helper(startRow, startColumn, m, n, maxMove, 0);
    }
};