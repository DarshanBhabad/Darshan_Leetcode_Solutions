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
    void reorderList(ListNode* head) {
        //if list size is 1 or 2 no nee to reorder 
        if(head->next==NULL) return;
        if(head->next->next==NULL) return;

        // we need 3 concepts 
        //1) find middle of link list 
        //2) from middle+1 to end consider it as new list and reverse that part of link list
        //3) now 2 pnts temp1 start from head and another start from head of revers elist and just copy the nodes

        //find middle 
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){ //both condn should be true;
        //if we get fast->next !=NULL  but fast ->next->next==NULL loop won't run
        // ity will give 1st middle 1-2-3-4 i.e 2 in case of 2nd middle do fast-!=NULL and fast->next!=NULL

        slow=slow->next;
        fast=fast->next->next;

        }
        //slow will point the middle
        ListNode* head2=slow->next; // store mid+1  to end list to new list or new haed
        slow->next=NULL; // point mid to NULL

        //reverse head2 list
        ListNode* curr=head2;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev; //prev node in curr next so reverse conn formed 
            prev=curr;// curr becomes prev 
            curr=next; //next become curr for coimg interation
     }
     //prev will point to new haed of reverse list;

     //now just copy the lists
     ListNode* temp1=head;
     ListNode* temp2=prev;
     ListNode* next1=NULL;
     ListNode* next2=NULL;
     
     while(temp2!=NULL){ //reverse list always smaller or eaual than list upto mid
        next1=temp1->next;
        next2=temp2->next;

      temp1->next=temp2;
      temp2->next=next1;

      temp1=next1;
      temp2=next2;
  
        


     }



    
        
      return ; 
    }
};