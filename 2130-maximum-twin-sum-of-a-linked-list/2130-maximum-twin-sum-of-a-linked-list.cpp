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
    int pairSum(ListNode* head) {
        
        vector<ListNode*>v;
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp);
            temp=temp->next;

        }
int n=v.size();
int sum=0;
        for(int i=0;i<=((n/2)-1);i++){
         sum=max(sum,v[i]->val+v[n-1-i]->val);

        }
return sum;
    }
};