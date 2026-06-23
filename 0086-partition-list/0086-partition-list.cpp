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
    ListNode* partition(ListNode* head, int x) {
       //what we try to do is that we will maintain 2 lists 
       // 1) smaller val tahn x 2
       //) greater or equal val than x            .......while preserving seq 

        ListNode* shead=NULL;//head and tail for ele smaller than x
        ListNode* stail=NULL;
        ListNode* lhead=NULL;  // head and tauil  for list formed for ele larg or equl to x
        ListNode* ltail=NULL;

        while(head){ //while head doesnt become NULL
        ListNode* nextnode=head->next;
        head->next=NULL; // seperated the curr node from others

        if(head->val<x){
            if(shead==NULL){
                shead=stail=head;
            }
            else{
                stail->next=head;
                stail=head;// tail pointing to last node of list of small ele
            }
        }
        else{ //greter or equal
          if(lhead==NULL){
                lhead=ltail=head;
            }
             else{
                ltail->next=head;
                ltail=head;// tail pointing to last node of list of small ele
            }

        }

        head=nextnode ; // updating head so that it will continue traversing original list;

           }

if(shead==NULL){ //small list was empty i.e no ele small than x were found
return lhead;

}

stail->next=lhead ; // else connecting the two lists
return shead;

    }
};