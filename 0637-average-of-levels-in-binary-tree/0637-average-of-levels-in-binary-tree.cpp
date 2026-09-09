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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        vector<int> number;
        long sum=0;
        queue<TreeNode*>q;
        TreeNode* curr;
        curr=root;
        q.push(curr);
        int n,temp;
        while(!q.empty()){
            n=q.size();
            temp=n;
            sum=0;
            while(n--){
                curr=q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            avg.push_back(sum/double(temp));

        }
        return avg;
    }
};