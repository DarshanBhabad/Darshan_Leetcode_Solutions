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
    ListNode* swapNodes(ListNode* head, int k) {
        //kth node from end is total_nodes-k+1 th node from start

        ListNode* temp = head;
        int tcnt=0;
        while(temp!=NULL){
            tcnt++;
            temp=temp->next;
        }
       
        //kth node from end = tcnt-n+1 th from start 
       int r= tcnt-k+1;
    

      temp=head; ///restoring temp
      ListNode* st=NULL;
      ListNode* end=NULL;
      int pcnt=0;
      while(temp!=NULL){
         pcnt++;
         if(pcnt==r) end=temp;
         if(pcnt==k)  st=temp;
         if(end && st) break; // both end  and st are not null i.e we found nodes to be swap so just break (optimization)
         temp=temp->next;

      }
        swap(st->val,end->val);
        return head;
    }
};