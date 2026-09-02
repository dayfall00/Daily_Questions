class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // base step

        if(nums.size() ==0) return {{}};
        

        // induction step
        int le= nums.back();
        nums.pop_back();
        vector<vector<int>> s1= subsets(nums);// power set of n-1 elements


        vector<vector<int>> s2;
        for(vector<int> subset : s1){
            subset.push_back(le);
            s2.push_back(subset);
        }
        vector<vector<int>> powerset = s1;
        powerset.insert(powerset.end(), s2.begin(), s2.end());
        return powerset;
    

    }
};

// backtracking

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<int>partialsubset;
          vector<vector<int>>powerset ;
          int i=0;
          dfs(nums, i, partialsubset, powerset);
          return powerset;
    }
private:
    void dfs( vector<int>& nums, int i, vector<int>& partialsubset,  vector<vector<int>>& powerset)
    {
        if(i== nums.size()) powerset.push_back(partialsubset);
        else{
            // without nums[i]
            dfs(nums, i+1, partialsubset, powerset);

            // with nums[i]
            partialsubset.push_back(nums[i]);
            dfs(nums, i+1, partialsubset, powerset);
            partialsubset.pop_back();

        }
    }
};