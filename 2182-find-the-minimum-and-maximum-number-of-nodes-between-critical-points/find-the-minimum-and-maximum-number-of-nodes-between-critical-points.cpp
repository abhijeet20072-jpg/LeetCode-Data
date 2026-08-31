/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==NULL)return {-1,-1};
        vector<int>dis;
        ListNode* prev=head;
        ListNode* curr =prev->next;
        ListNode* n=curr->next;
        int a,b,c;
        int i=2;
        while(n){
            a=prev->val;
            b=curr->val;
            c=n->val;
            if(b>a&&b>c)dis.push_back(i);
            else if(b<a&&b<c)dis.push_back(i);
            prev=curr;
            curr=n;
            n=n->next;
            i++;
        }
        if(dis.size()==1||dis.size()==0)return {-1,-1};
        a=INT_MAX;
        b=dis.back()-dis[0];
        for(int i=1;i<dis.size();i++){
            a=min(a,dis[i]-dis[i-1]);
        }
        return{a,b};
    }
};