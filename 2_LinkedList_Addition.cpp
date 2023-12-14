//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode *head = new ListNode(0);
        head->next = NULL;
        ListNode *curr = head;
        int carry = 0;
        while(l1 || l2){
            int sum = 0;
            if(l1 && l2){
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1){
                sum = l1->val + carry;
                l1 = l1->next;
            }else{
                sum = l2->val + carry;
                l2 = l2->next;
            }
            ListNode *tmp = new ListNode(0);
            tmp->val = sum % 10;
            carry = sum / 10;
            tmp->next = NULL;
            curr->next = tmp;
            curr = curr->next;
        }
        if(carry) {
            ListNode *tmp = new ListNode(0);
            tmp->val = carry;
            tmp->next = NULL;
            curr->next = tmp;
        }
        return head->next;
    }
};