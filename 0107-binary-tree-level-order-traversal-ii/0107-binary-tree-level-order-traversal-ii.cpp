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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return{};
        queue<TreeNode*> q;
        TreeNode* node;
        q.push(root);
        while(!q.empty()){
            vector<int> ans;
            int n=q.size();
            while(n--){
                node=q.front();
                ans.push_back(node->val);
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                }
                
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            res.push_back(ans);
        }
            reverse(res.begin(),res.end());
            return res;
    }
};