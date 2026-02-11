class Solution {
public:
    const long long NEG = -4e18;
    long long dp[101][101][101];

    long long maxScore(vector<int>& nums1,
                       vector<int>& nums2,
                       int k) {

        int n = nums1.size();
        int m = nums2.size();

        // initialize DP with NEG
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                for (int t = 0; t <= k; t++)
                    dp[i][j][t] = NEG;

        // base case
        dp[0][0][0] = 0;

        // fill DP table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int t = 0; t <= k; t++) {

                    if (i > 0)
                        dp[i][j][t] =
                            max(dp[i][j][t], dp[i-1][j][t]);

                    if (j > 0)
                        dp[i][j][t] =
                            max(dp[i][j][t], dp[i][j-1][t]);

                    if (i > 0 && j > 0 && t > 0 &&
                        dp[i-1][j-1][t-1] != NEG) {

                        dp[i][j][t] = max(
                            dp[i][j][t],
                            dp[i-1][j-1][t-1]
                            + 1LL * nums1[i-1] * nums2[j-1]
                        );
                    }
                }
            }
        }

        return dp[n][m][k];
    }
};