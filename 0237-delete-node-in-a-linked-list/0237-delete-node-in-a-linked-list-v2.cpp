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
    void deleteNode(ListNode* node) {
    
    // ListNode* temp=node;
    // ListNode* prev;
    // while(temp->next!=NULL){
    //     temp->val=temp->next->val;
    //     prev=temp;
    //     temp=temp->next;
        
    // }
    
    // prev->next=NULL;
    
    

  // APPROACH 2 O(1)
  //as here we only hav tpo play wityh val of nodes and not nodes itself 
   node->val=node->next->val;
   node->next=node->next->next;        
    }
};