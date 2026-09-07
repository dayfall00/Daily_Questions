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
vector<vector<int>> res;
void sum(TreeNode* root, int targetSum,int cs, vector<int> result){
        if (root == NULL) {
            return ;
        }
        cs += root -> val;
        result.push_back(root->val);
        if(root-> left == NULL && root-> right==NULL){
            if(cs == targetSum){
            res.push_back(result);

            return;
        }
        }
        sum(root->left,targetSum,cs,result);
        sum(root->right,targetSum,cs,result);
        result.pop_back();
        
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> result;
        sum(root,targetSum,0,result);
        return res;

    }
};