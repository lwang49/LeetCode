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
            
            int sum = l1 -> val + l2 -> val;
            int carry = sum/10;
            ListNode *ret = new ListNode(sum%10);
            ListNode *result = ret;
     
            while(l1 -> next != nullptr || l2 -> next != nullptr)
            {
                //l1 and l2 both not null
                if (l1 -> next != nullptr && l2 -> next != nullptr)
                {
                    l1 = l1 -> next;
                    l2 = l2 -> next;
                    sum = l1 -> val + l2 -> val;
                    result -> next = new ListNode((sum + carry)%10);
                    carry = (sum + carry)/10;
                    result = result -> next;
                }
                //only l1
                else if (l2 -> next != nullptr)
                {
                    l2 = l2 -> next;
                    sum = l2 -> val;
                    result -> next = new ListNode((sum + carry)%10);
                    carry = (sum + carry)/10;
                    result = result -> next;
                }
                //only l2
                else if (l1 -> next != nullptr)
                {
                    l1 = l1 -> next;
                    sum = l1 -> val;
                    result -> next = new ListNode((sum + carry)%10);
                    carry = (sum + carry)/10;
                    result = result -> next;
                }
            }
            
            if (carry != 0)
            {
                result -> next = new ListNode(carry);
                result = result -> next;
            }
            
            return ret;
    }
};