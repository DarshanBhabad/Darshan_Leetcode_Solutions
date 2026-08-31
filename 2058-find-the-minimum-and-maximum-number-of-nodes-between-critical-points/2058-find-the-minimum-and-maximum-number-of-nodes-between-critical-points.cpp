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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>d;
        int c=0;
        ListNode* temp=head;
        ListNode* prev=NULL;
        //find all critical points put them in array
        while(temp!=NULL){
            c++;
            if(prev!=NULL && temp->next!=NULL){
            if((temp->val>prev->val&&temp->val>temp->next->val) ||(temp->val<prev->val&&temp->val<temp->next->val)) d.push_back(c);
            }
            prev=temp;
            temp=temp->next;

        }
   //we told to output mxd and mnd fron 2 distinct cp , if less than 2 output {-1,-1}
        if(d.size()<2) return {-1,-1};
//else
        int mxd=0;
        int mnd=INT_MAX;
        mxd=d.back()-d[0];  //difference betn farthest ctp from 1st
        // and mnd is min dist betn adjacent

        for(int i=1;i<d.size();i++){
              mnd=min(mnd,d[i]-d[i-1]);
        }

return {mnd,mxd};
        
    }
};