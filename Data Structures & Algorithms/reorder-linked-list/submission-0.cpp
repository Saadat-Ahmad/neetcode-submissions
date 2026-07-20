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
    void reorderList(ListNode* head) {
        deque<ListNode*> q;
        ListNode* curr = head;
        while(curr){
            q.push_back(curr);
            curr = curr->next;
        }
        while(q.size()>1){
            q.back()->next = q.front()->next;
            q.front()->next = q.back();
            q.pop_front();
            q.pop_back();
        }
        q.front()->next = nullptr;
    }
};