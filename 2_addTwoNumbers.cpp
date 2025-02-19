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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1; ListNode* t2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* tmp = dummy;
        int carry = 0;
        while(t1 && t2){
            int sum = t1->val + t2->val + carry;
            if(sum >= 10){
                carry = sum/10;
            }
            else if(sum < 10){
                carry = 0;
            }
            sum = sum%10;
            ListNode* node = new ListNode(sum);
            tmp->next = node;
            tmp = node;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1){
            int sum = t1->val + carry;
            if(sum >= 10){
                carry = sum/10;
            }
            else if(sum < 10){
                carry = 0;
            }
            sum = sum%10;
            ListNode* node = new ListNode(sum);
            tmp->next = node;
            tmp = node;
            t1 = t1->next;
        }
        while(t2){
            int sum = t2->val + carry;
            if(sum >= 10){
                carry = sum/10;
            }
            else if(sum < 10){
                carry = 0;
            }
            sum = sum%10;
            ListNode* node = new ListNode(sum);
            tmp->next = node;
            tmp = node;
            t2 = t2->next;
        }
        if(carry > 0){
            cout<<"here";
            ListNode* node = new ListNode(carry);
            tmp->next = node;
            tmp = node;
        }
        return dummy->next;
    }
};
