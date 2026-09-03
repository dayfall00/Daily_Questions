/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void dfs(vector<int>& val, TreeNode* root){
        if(root==NULL) return;
        val.push_back(root->val);
        dfs(val,root->left);
        dfs(val,root->right);
    }
   static bool compareBySecond(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
        }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int>val;
        dfs(val,root);
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for(auto x:val){
            mp[x]++;
            st.insert(x);
        }
       vector<pair<int, int>> rf;
       for(auto x: st){
        rf.push_back({x,mp[x]});
       }
       sort(rf.begin(), rf.end(), compareBySecond);
       if(rf.empty()) return {};
       vector<int> ans;
       int max=rf[0].second;
       int i=0;
       while(i < rf.size() && rf[i].second == max) {
        ans.push_back(rf[i].first);
        i++;
        }  
       return ans;    
   }
};