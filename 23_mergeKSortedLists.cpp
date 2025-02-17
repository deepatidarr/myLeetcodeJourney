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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        int k = lists.size();
        if(k==0) return NULL;
        ListNode* dummy = new ListNode(-1);
        ListNode* tmp = dummy;
        for(int i=0; i<k; i++){
            if(lists[i] != NULL)
                pq.push({lists[i]->val, lists[i]});
        }

        while(pq.size()){
            ListNode* node = pq.top().second;
            tmp->next = node;
            tmp = tmp->next;
            pq.pop();
            if(node->next){
                pq.push({node->next->val, node->next});
            }
        }

        return dummy->next;
    }
};
