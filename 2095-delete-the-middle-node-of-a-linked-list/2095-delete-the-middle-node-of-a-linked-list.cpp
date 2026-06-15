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
    ListNode* deleteMiddle(ListNode* head) {

        //edge case 
        if(head->next==NULL) return NULL;



        ListNode* slow=head;
        ListNode* fast= head;
        ListNode* prev=slow;

        while(fast && fast->next){ //fast !=NULL and fast->next!=NULL as we incrementing fast twice so to avoid NULL->next error;
        prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        //now slow will point to middle node and prev will point node prev of middle
        prev->next=slow->next;
        delete(slow);
        // if(head==NULL) return NULL;
        return head;
    }
};