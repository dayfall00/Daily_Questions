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
private:
void dfs(vector<int>& ans, TreeNode* root){
    if(!root) return;
    dfs(ans,root->left);
    ans.push_back(root->val);
    dfs(ans,root->right);
}
void merge(vector<int>& r1,vector<int>& r2,vector<int>& ans){
    int i,j,a=0,b=0;
    i=r1.size();
    j=r2.size();
    while(a<i && b<j){
        if(r1[a]<r2[b]){
            ans.push_back(r1[a]);
            a++;
        }
        else{
            ans.push_back(r2[b]);
            b++;
        }
    }
    while(a<i){
        ans.push_back(r1[a]);
        a++;
    }
    
    while(b<j){
        ans.push_back(r2[b]);
        b++;
    }
}
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> r1,r2,ans;
        dfs(r1, root1);
        dfs(r2, root2);
        merge(r1,r2,ans);
        return ans;
    }
};