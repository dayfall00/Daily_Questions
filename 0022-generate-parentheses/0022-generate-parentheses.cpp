class Solution {
public:
    vector<string> generateParenthesis(int n) {
    vector<string> all;
    string par; // partial parenthesis string
    int n1 = 0, n2 = 0;
    dfs(n, n1, n2, par, all);
    return all;
        }

private:
 void dfs(const int n, int n1, int n2, string& par, vector<string> & all){
    if(n1 ==n  && n2== n ) all.push_back(par);

    else{

        if(n1<n){
            par.push_back('(');
            dfs(n,n1+1,n2,par,all);
            par.pop_back();

        }
        if(n2<n1){
            par.push_back(')');
            dfs(n,n1,n2+1, par, all);
            par.pop_back();
        }
    }
 }
};