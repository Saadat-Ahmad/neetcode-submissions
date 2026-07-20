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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        ListNode* res;
        ListNode* cmp1;
        ListNode* cmp2;
        ListNode* ans;
        if (list1->val < list2->val) {res = list1; cmp1 = list1->next; cmp2 = list2;}
        else {res = list2; cmp1 = list1; cmp2 = list2->next;}
        ans = res;
        while(cmp1 != nullptr || cmp2 != nullptr){
            if(cmp1 == nullptr) {res->next = cmp2; cmp2 = nullptr; break;}
            else if (cmp2 == nullptr) {res->next = cmp1; cmp1 = nullptr; break;}
            if(cmp1->val < cmp2->val) {res->next = cmp1; res = cmp1; cmp1 = cmp1->next;}
            else {res->next = cmp2; res = cmp2; cmp2 = cmp2->next;}
        }
        return ans;

    }
};