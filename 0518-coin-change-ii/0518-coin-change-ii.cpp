
class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins,
              vector<vector<int>>& dp) {

        if (amount == 0) return 1;

        if (ind == coins.size()) return 0;

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int notTake = solve(ind + 1, amount, coins, dp);

        int take = 0;

        if (coins[ind] <= amount) {
            take = solve(ind, amount - coins[ind], coins, dp);
        }

        return dp[ind][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(
            coins.size(), vector<int>(amount + 1, -1)
        );

        return solve(0, amount, coins, dp);
    }
};
