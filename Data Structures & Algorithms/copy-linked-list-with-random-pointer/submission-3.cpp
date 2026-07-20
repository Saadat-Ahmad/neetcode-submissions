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
        Node* node = head;
        Node* buff;
        while(node){
            dummy->next = new Node(node->val); 
            dummy = dummy->next;
            mp[node] = dummy;
            node = node->next;
        }
        node = head;
        dummy = res->next;
        while(node){
            dummy->random = mp[node->random];
            dummy = dummy->next;
            node = node->next;
        }
        return res->next;
    }
};
