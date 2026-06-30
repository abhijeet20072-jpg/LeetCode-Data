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
    int f(TreeNode* root,int a){
        if(!root)return 0;
        a=a*10+root->val;
        if(!root->left&&!root->right)return a;
        return f(root->left,a)+f(root->right,a);
      
    }
    int sumNumbers(TreeNode* root) {
        return f(root,0);
    }
};