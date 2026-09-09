/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        queue<Node*>q;
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>a;
            for(int i=0;i<n;i++){
                Node* temp=q.front();
                q.pop();
                a.push_back(temp->val);
                vector<Node*>b=temp->children;
                for(int i=0;i<b.size();i++){
                    if(b[i]!=nullptr)q.push(b[i]);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};