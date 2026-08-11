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
 //QUICK SORT
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        multimap<int,ListNode*>m; //to store duplicat ekeys in sorted order
        ListNode* temp=head;
        while(temp!=NULL){
            // m[temp->val]=temp;
            m.insert({temp->val, temp});
            temp=temp->next;

        }
        if(m.empty()) return NULL;

        ListNode* nh=NULL;
        ListNode* t=NULL;

   
        for(auto p:m){

            if(nh==NULL){
                nh=p.second;
                t=nh;
                
            }
            else{
                t->next=p.second;
                t=t->next;
            }

        }
        t->next=NULL;


return nh;
    }
};