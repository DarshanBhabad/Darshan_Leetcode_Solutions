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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
ListNode* findmiddle(ListNode* head,ListNode* &prev){
    ListNode* slow=head;
    ListNode* fast=head;
  //previous is helpful to break the list into two halves
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow; //points to middle node

}

TreeNode* buildtree(ListNode* head){

    //BASE CASES
    if(head==NULL) return NULL;
    if(head->next==NULL) return new TreeNode(head->val);

    ListNode* prev=NULL;
    ListNode* middle=findmiddle(head,prev);
    //prev is taken as refrence so it will pnt nod ebfore middle
    prev->next=NULL;  //splited;

   TreeNode* root=new TreeNode(middle->val);

   
    root->left=buildtree(head);
    root->right=buildtree(middle->next);

    return root;
    
}


TreeNode* sortedListToBST(ListNode* head) {
    
    

   return buildtree(head);
     


      
    }
};