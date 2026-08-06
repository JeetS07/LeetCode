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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { // sort and merge 2 lists
        if(!l2) return l1;
        if(!l1) return l2;

        if(l1->val<=l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }

        else {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }

    ListNode* partitionAndMerge(int left, int right, vector<ListNode*>& lists){
        if(left>right) return NULL;
        if(left==right) return lists[left];

        int mid = left+(right-left)/2;

        ListNode* l1 = partitionAndMerge(left,mid,lists); // break left
        ListNode* l2 = partitionAndMerge(mid+1,right,lists); // break right

        return mergeTwoLists(l1,l2); // sort and merge
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;

        return partitionAndMerge(0,k-1,lists);
    }
};

// Recursion, merge sort
// we are breaking all lists and merging individual list using mergeTwoLists()