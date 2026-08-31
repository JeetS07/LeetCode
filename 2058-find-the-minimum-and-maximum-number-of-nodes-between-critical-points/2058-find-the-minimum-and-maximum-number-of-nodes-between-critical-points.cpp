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
        ListNode* a=head;
        ListNode* b=head->next;
        ListNode* c=head->next->next;

        vector<int> arr;
        int i=1;
        while(a && b && c){
            if((a->val<b->val && b->val>c->val) || (a->val>b->val && b->val<c->val)) arr.push_back(i);
            a=a->next;
            b=b->next;
            c=c->next;

            i++;
        }

        int n=arr.size();
        if(n<2) return {-1,-1};

        int minD=INT_MAX;
        for(int i=1;i<n;i++) minD=min(minD,arr[i]-arr[i-1]);
        return {minD,arr[n-1]-arr[0]};
    }
};