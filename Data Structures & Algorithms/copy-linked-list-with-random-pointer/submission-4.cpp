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
            if(mp.find(node) == mp.end()) mp[node] = new Node(node->val);
            dummy->next = mp[node]; 
            dummy = dummy->next;
            if (!node->random) dummy->random = nullptr;
            else if (mp.find(node->random) == mp.end()){
                mp[node->random] = new Node(node->random->val);
                dummy->random = mp[node->random];
            } 
            else dummy->random = mp[node->random];
            node = node->next;
        }
        return res->next;
    }
};
