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
    
    ListNode* removeNodes(ListNode* head) {
        vector<int>sa;
        while(head){
            sa.push_back(head->val);
            head=head->next;
        }
        vector<int>v;
        int rm=INT_MIN;
        for(int i=sa.size()-1;i>=0;i--){
            if(sa[i]>=rm)v.push_back(sa[i]);
            rm=max(rm,sa[i]);
        }
        ListNode dummy(0);
        ListNode* curr=&dummy;
        for(int i=v.size()-1;i>=0;i--){
            ListNode *t=new ListNode(v[i]);
            curr->next=t;
            curr=t;
        }
        return dummy.next;
    }
};