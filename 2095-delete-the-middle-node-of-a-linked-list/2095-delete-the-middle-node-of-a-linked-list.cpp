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
        ListNode* prev;

        while(fast && fast->next){ //fast !=NULL and fast->next!=NULL as we incrementing fast twice so to avoid NULL->next error;
        prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        //now slow will point to middle node and prev will point node prev of middle
        prev->next=slow->next;
        delete(slow);
        
        return head;


        //OR dont have to use prev pntr

        
//        class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         ListNode* fast = head, *slow = head;

//         if (fast->next == NULL) return NULL;
//         fast = fast->next->next;  //increment fast before loop only so after loop slow will point to node before the middle node
//         while (fast != NULL && fast->next != NULL) {
//             fast = fast->next->next;
//             slow = slow->next;
//         }

//         slow->next = slow->next->next;  //now slow ehich is prev node of middle sets it next as     n       middle's   (slow->next)-> next
//         return head;
//     }
// };
    }
};