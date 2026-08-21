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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //TC= O(n)  sc=O(1)
        //nth node from start is total_nodes-n+1 th node from start

        ListNode* temp = head;
        int tcnt=0;
        while(temp!=NULL){
            tcnt++;
            temp=temp->next;
        }
        temp=head;
        //node to be remove from start
       int r= tcnt-n+1;

       // If removing the first node  //edge case
        if (r == 1) {
            return head->next;
        }

       int pcnt=0; //temporary cnt
    ListNode* prev=NULL;
       while(pcnt<r-1){
        prev=temp;
        temp=temp->next;
        pcnt++;
       }
       //now temp points the node to be remove
      prev->next=temp->next;

      return head;

    }
};