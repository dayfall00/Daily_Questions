class Solution {
    int n;
public:

    vector<vector<string>> partition(string s) {
       n=s.size();
        vector<vector<string>> all;
        vector<string> par;
        dfs(s,0,par,all);
        return all;
    }
private:
void dfs(string& s, int i,vector<string> &par, vector<vector<string>> &all){
    if(i== s.size()) all.push_back(par);
    else{
        for(int j=i;j<n;j++){
            if(isPal(s,i,j)){
                string seg= s.substr(i, j-i+1);
                par.push_back(seg);
                dfs(s,j+1,par,all);
                par.pop_back();
            }
        }
    }
}
bool isPal(string&s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;j--;
    }
    return true;
}
};