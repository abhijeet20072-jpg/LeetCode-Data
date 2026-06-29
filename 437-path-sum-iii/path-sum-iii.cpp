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
    int f(TreeNode* root, int targetSum,long long s){
        if(!root)return 0;
        s+=root->val;
        int c=(s==targetSum);
        c+=f(root->left,targetSum,s);
        c+=f(root->right,targetSum,s);
        return c;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
       int ans=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
            ans+=f(t,targetSum,0);
        }

       return ans;
    }
};