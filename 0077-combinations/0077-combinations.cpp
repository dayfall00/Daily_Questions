class Solution1 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> partialSubset;

        dfs(n, 1, k, partialSubset, combinations);

        return combinations;
    }

private:
    void dfs(int n, int i, int k,
             vector<int>& partialSubset,
             vector<vector<int>>& combinations) {

        // Base case
        if (i > n) {
            if (partialSubset.size() == k) {
                combinations.push_back(partialSubset);
            }
            return;
        }

        // Without i
        dfs(n, i + 1, k, partialSubset, combinations);

        // With i
        partialSubset.push_back(i);
        dfs(n, i + 1, k, partialSubset, combinations);
        partialSubset.pop_back();
    }
};

// backtracking
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> partial;
        dfs(n,k,partial, combinations);
        return combinations;

    }
private:
    void dfs( int n, int k , vector<int>& partial, vector<vector<int>>& combinations){

        if(k == 0) combinations.push_back(partial);
        else{
            // without n
            if(n>k) dfs(n-1,k,partial, combinations);

            // with n

            partial.push_back(n);
            dfs(n-1,k-1,partial, combinations);
            partial.pop_back();
        }
    }
};