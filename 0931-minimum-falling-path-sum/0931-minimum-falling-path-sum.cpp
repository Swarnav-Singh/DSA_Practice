class Solution {
public:
    int solve(vector<vector<int>> &dp, vector<vector<int>> &matrix, int i, int j) {
        if (j < 0 || j >= matrix.size()) return INT_MAX;
        if (i == 0) return matrix[0][j];
        if (dp[i][j] != INT_MAX) return dp[i][j];
        int left = solve(dp, matrix, i-1, j-1);
        int up = solve(dp, matrix, i-1, j);
        int right = solve(dp, matrix, i-1, j+1);
        int ans = min(left, min(up, right));
        return dp[i][j] = matrix[i][j] + ans; 
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp (n, vector<int>(n, INT_MAX));
        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            ans = min(ans, solve(dp, matrix, n-1, j));
        }
        return ans;
    }
};