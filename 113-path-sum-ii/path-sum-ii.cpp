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
    void f(TreeNode* root, int targetSum ,int s,vector<int>& d,vector<vector<int>>& ans){
        if(!root){
            return;
        }
        s+=root->val;
        d.push_back(root->val);
        if(!root->left&&!root->right&&s==targetSum){
            ans.push_back(d);
        }
        if(root->left)f(root->left,targetSum,s,d,ans);
        if(root->right)f(root->right,targetSum,s,d,ans);
        d.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>d;
        f(root,targetSum,0,d,ans);
        return ans;
    }
};