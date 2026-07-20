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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int size = 0, j = 0;
        while(curr){
            curr = curr->next;
            size++;
        }
        curr = head;
        while(curr && size-j >= n){
            if (size-j == n){
                if(prev) prev->next = curr->next;
                else return curr->next;
            }
            prev = curr;
            curr = curr->next;
            j++;
        }
        return head;
    }
};