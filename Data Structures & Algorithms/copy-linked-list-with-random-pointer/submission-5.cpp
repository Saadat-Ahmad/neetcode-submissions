/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* dummy = new Node(0);
        Node* res = dummy;
        while(head){
            if(mp.find(head) == mp.end()) mp[head] = new Node(head->val);
            dummy->next = mp[head]; 
            dummy = dummy->next;
            if (!head->random) dummy->random = nullptr;
            else if (mp.find(head->random) == mp.end()){
                mp[head->random] = new Node(head->random->val);
                dummy->random = mp[head->random];
            } 
            else dummy->random = mp[head->random];
            head = head->next;
        }
        return res->next;
    }
};
