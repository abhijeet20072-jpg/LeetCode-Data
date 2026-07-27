class Solution {
public:
    int maxProduct(vector<int>& nums) {
       priority_queue<int>pq;
       for(int x: nums){
        pq.push(x);
       }
       int l=pq.top();
       pq.pop();
       int sl=pq.top();
       l--;
       sl--;
       return l*sl;
    }
};