// recursion
class Solution1 {
private:
int solve(int i, int j, string txt1, string txt2){
    if(i<0 || j<0) return 0;

    if(txt1[i]==txt2[j]) return 1+solve(i-1,j-1,txt1,txt2);

    else return( max(
        solve(i-1,j,txt1,txt2),
        solve(i,j-1,txt1,txt2)
    ));
}
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        return solve(m-1,n-1,text1,text2);
    }
};
// backtracking
class Solution2 {
private:
int ans=0;
void solve(int i, int j, string& txt1, string& txt2,string& curr){
    if(i==txt1.length() || j== txt2.length()){
        ans=max(ans, (int)curr.length());
        return;
    }
    if(txt1[i]==txt2[j]){
    curr.push_back(txt1[i]);
    solve(i+1,j+1,txt1,txt2,curr);
    curr.pop_back();
    }

    else{
        solve(i+1,j,txt1,txt2,curr);
        solve(i,j+1,txt1,txt2, curr);
    }
}
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        string curr="";
     
        solve(0,0,text1,text2,curr);
        return ans;
    }
};

// memoization
class Solution {
private:
vector<vector<int>>dp;
int solve(int i, int j, string& txt1, string& txt2){
    if(i==txt1.length() || j== txt2.length()){
        return 0;
    }

    if(dp[i][j] !=-1) return dp[i][j];
    
    if(txt1[i]==txt2[j]){
        dp[i][j]=1+solve(i+1,j+1,txt1,txt2);
    }

    else{
        return dp[i][j]=max(solve(i+1,j,txt1,txt2),
        solve(i,j+1,txt1,txt2));
    }
    return dp[i][j];
}
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();

        dp.assign(m,vector<int>(n,-1));
     
        return solve(0,0,text1,text2);
        
    }
};