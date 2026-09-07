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
    bool sum(TreeNode* root, int targetSum, int cs){
        if (root == NULL) {
            return false;
        }
        cs += root -> val;
        if(root-> left == NULL && root-> right==NULL && cs == targetSum){
            return true;
        }
        bool l=sum(root->left,targetSum,cs);
        bool r=sum(root->right,targetSum,cs);
        
        return l || r;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
       return sum(root,targetSum,0);
    }
};