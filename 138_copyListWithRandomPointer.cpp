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
        if(head==NULL) return head;
        Node* tmp = head;
        Node* newHead = new Node(head->val);
        unordered_map<Node*, Node*> mp;
        mp.insert({head,newHead});
        while(tmp){
            if(mp.find(tmp) == mp.end()){
                Node* node = new Node(tmp->val);
                mp[tmp] = node;
            }
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp){
            if(tmp->next) mp[tmp]->next = mp[tmp->next];
            if(tmp->random) mp[tmp]->random = mp[tmp->random];
            tmp = tmp->next;
        }
        return mp[head];
    }
};
