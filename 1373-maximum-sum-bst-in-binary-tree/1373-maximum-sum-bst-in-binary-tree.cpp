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
int maxs=0;
bool sum1(TreeNode* root, int& minval, int&maxval,int&sum ){
    if(root ==NULL){
        minval=INT_MAX;
        maxval=INT_MIN;
        sum=0;
        return true;
    }

    int lmin,lmax,lsum;
    int rmin,rmax,rsum;

    bool l=sum1(root->left,lmin,lmax,lsum);
    bool r=sum1(root->right,rmin,rmax,rsum);
    if(!l || !r || root->val<=lmax|| root->val >=rmin){
        return false;
    }

    sum= lsum+root->val+rsum;

    if(maxs< sum){
        maxs=sum;
    }
    minval=min(lmin,root-> val);
    maxval=max(rmax,root->val);

    return true;
}

public:
    int maxSumBST(TreeNode* root) {
        int minval,maxval,sum;
        sum1(root,minval,maxval,sum);

        return maxs;
        
    }
};