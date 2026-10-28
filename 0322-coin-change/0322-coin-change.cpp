class Solution1 {// exhaustive search
    private:
    void solve(vector<int>& coins, int amt, int count, int& ans, int i){
        if(amt==0){
            ans=min(ans,count);
        }
        if(i<0 || amt<0) return;

        // dont pick
        solve(coins,amt,count,ans,i-1);

        // pick
        solve(coins,amt-coins[i],count+1,ans,i);


    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans= INT_MAX;

        solve(coins,amount,0,ans,coins.size()-1);

        return ans==INT_MAX?-1:ans;
    }
};

class Solution {// memoization
    private:
    int solve(vector<int>& coins, int amt, int i,vector<vector<int>>&dp){
        if(amt==0){
            return 0;
        }
        if(i<0 || amt<0 )  return 1e9;

        if(dp[i][amt]!=-1) return dp[i][amt];

        // dont pick
        int dpk=solve(coins,amt,i-1,dp);

        // pick
        int pk=1e9;
        if(coins[i]<=amt){
         pk=1+solve(coins,amt-coins[i],i,dp);
        }
       return dp[i][amt]=min(pk,dpk);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int ans= INT_MAX;
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        ans=solve(coins,amount,coins.size()-1,dp);

        return ans==1e9?-1:ans;
    }
};