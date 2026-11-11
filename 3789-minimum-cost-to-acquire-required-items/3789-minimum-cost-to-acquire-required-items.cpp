class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        //we need to choose the cost1/cost 2  if cost 1 + cost 2 is < cost both 
        long long ans =0;
        if(cost1+cost2>costBoth){//choose cost both 
            //  ans=max(need1,need2)*costBoth; //max and min func tc is O(1)
            ans = 1LL*min(need1,need2)*costBoth;
            long long diff=abs(need1-need2);
            long long c=1LL*diff*costBoth;
            long long j;
            if(need1>need2){
                 j=diff*cost1;
            }
            else j=diff*cost2;
            ans+=min(c,j);


        }
        else 
        ans=1LL*need1*cost1+1LL*need2*cost2;

        return ans;

    }
};