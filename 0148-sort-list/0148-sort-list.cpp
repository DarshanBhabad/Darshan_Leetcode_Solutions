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

ListNode* merge(ListNode* L1,ListNode* L2){
    ListNode* d=new ListNode(0);
    ListNode* temp = d;

    
    while(L1 && L2){ //if anyone of tehm become sNULL stop
          if(L1->val<=L2->val){ //both L1 and L2 are already sorted 
            temp->next=L1;
            L1=L1->next;
          }
          else{
             temp->next = L2;
                L2 = L2->next;
          }

          temp = temp->next;

    }

    if(L2!=NULL){
        temp->next=L2;
    }
    else temp->next=L1; //remaining add

    return d->next; // 0(d) -> ...merged list
}

ListNode* sortList(ListNode* head) {
        
//         For LeetCode 148 – Sort List, the expected O(n log n) solution is Merge Sort on the linked list.
// The key idea is:
// 1. Find the middle of the linked list.
// 2. Split it into two halves.
// 3. Recursively sort both halves.
// 4. Merge the two sorted halves.

// BC 
if(head==NULL || head->next==NULL ){
    return head;
}

//find midle 
ListNode* slow=head;
ListNode* fast =head->next;
while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;

}
//slow points to 1st middle 
ListNode* l2=slow->next; //right part
slow->next=NULL; //both lists are sepearated 


//sort both parts 
ListNode* l1=sortList(head); // first entire right part will be sorte dand merged 
l2=sortList(l2); 
//merge both parts 
return merge(l1,l2);

    }
};