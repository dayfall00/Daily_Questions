class Solution {
public:
    vector<vector<int>> ans;
    void f1(vector<int>& candidates, int target, int idx, vector<int>& bans){
      
      if(target == 0){
        ans.push_back(bans);
        return;
      }
      if(idx == candidates.size())
        return;
      
      if(candidates[idx]<=target){
        bans.push_back(candidates[idx]);
        f1(candidates,target-candidates[idx],idx,bans);
        bans.pop_back();
        
      }
        f1(candidates,target,idx+1,bans);
      
      return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> bans;
         f1(candidates,target,0,bans);
         return ans;
    }
};