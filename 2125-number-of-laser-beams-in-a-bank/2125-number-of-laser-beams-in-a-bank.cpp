class Solution {
public:
int cnt(string s){
    int c=0;
    for(int i=0;i<s.size();i++){
       if(s[i]=='1')c++;
    }
    return c;
}
    int numberOfBeams(vector<string>& bank) {
        //gra-h level order traversal ---------------------------------
//TC=O(M*N)
        int n=bank.size();
        int st=cnt(bank[0]);
        // bool flag=false;
       int ans=0;
        for(int i=1;i<n;i++){
            //  if(st>0) flag=true;
             int curr=cnt(bank[i]);
            if(curr>0 && st>0){ //prev has 1's and current also
               ans+=st*curr; //total beams 
                // st=curr;
            }
            if(curr>0) st=curr; // in case falg is false that is st was prev 0 we have to take st to curr
            // st=curr; // in any case we have to update our st as prev doent have 1 then also we have to update the st

        }

return ans;
    }
};