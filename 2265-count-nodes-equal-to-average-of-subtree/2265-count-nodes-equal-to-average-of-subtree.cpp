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
int ans=0;
pair<int,int> avg(TreeNode* node){
    if(node -> left == NULL && !node -> right){
         ans++;
        return {node->val,1};
       
    }
    pair<int, int> lt,rt;
    int sum, count=1;
    sum=node->val;
    
    if(node -> left){
        lt=avg(node->left);
        sum+=lt.first;
        count+=lt.second;
    }
    if(node-> right){
        rt=avg(node->right);
         sum+=rt.first;
         count+=rt.second;
    }
    
    int avg1;
    avg1=sum/count;
    if(avg1== node-> val) ans++;
    return {sum,count};
}
public:
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        pair<int, int> res;
        res= avg(root);
        return ans;
    }
};