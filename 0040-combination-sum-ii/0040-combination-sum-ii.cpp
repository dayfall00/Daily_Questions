class Solution {
public:
 set<vector<int>> ans;
    void f1(vector<int>& candidates, int target, int idx, vector<int>& bans){
      
      if(target == 0){
        ans.insert(bans);
        return;
      }
      if(idx == candidates.size())
        return;
      
      if(candidates[idx]<=target){
        bans.push_back(candidates[idx]);
        f1(candidates,target-candidates[idx],idx+1,bans);
        bans.pop_back();
        
      }
             // Skip all duplicates before NOT TAKE
        int nextIdx = idx + 1;

        while (nextIdx < candidates.size() &&
               candidates[nextIdx] == candidates[idx]) {
            nextIdx++;
        }

        // DON'T TAKE
        f1(candidates, target, nextIdx, bans);
      
      return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> bans;
         f1(candidates,target,0,bans);
        vector<vector<int>> result(ans.begin(), ans.end());
         return result;
    }
};