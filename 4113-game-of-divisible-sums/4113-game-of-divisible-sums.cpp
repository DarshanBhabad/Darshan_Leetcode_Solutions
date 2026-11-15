class Solution {
public:
 long long getsum(int i, vector<int>&nums, vector<long long>&dp){
     int n=nums.size();
     if(i>=n) return 0;
     if(dp[i]!=LLONG_MIN) return dp[i];
     //c1 take one element
     long long s1=nums[i];
     long long t1=LLONG_MIN;
     if(s1%3==0) t1=s1-getsum(i+1,nums,dp); // bobs tur will be next who will minimize it 
     else t1=s1+getsum(i+1,nums,dp);

     //c2 take 2 ele
      long long t2=LLONG_MIN;
     if(i+1<n){
         long long s2=nums[i]+nums[i+1];
         if(s2%3==0) t2=s2-getsum(i+2,nums,dp);
         else t2=s2+getsum(i+2,nums,dp);
     }

     return dp[i]=max(t1,t2);
     
 }



    //recursion O(2N)
    // //optimally play so alice wants to maximixe the sa-sb and bob want to minimize sa-sb
    // long long getsum(int i,int n , vector<int>&nums,long long sa, long long  sb,bool turn){
    //     //bc game ends
    //     if(i>=n) return sa-sb;
    //     long long ans;
    //     // c1 take one ele
    //     long long sum1=nums[i];
    //     if(turn){ // alice
    //         if(sum1 %3==0) ans= getsum(i+1,n,nums,sa+sum1,sb,false);
    //         else ans=getsum(i+1,n,nums,sa+sum1,sb,true); 
    //     }
    //     else {//bobs turn
    //         if(sum1%3==0) ans=getsum(i+1,n,nums,sa,sb+sum1,true); //nest turn will be alice
    //         else ans=getsum(i+1,n,nums,sa,sb+sum1,false);
            
    //     }

    //     // c2  take two elements 
    //     if(i+1<n){ //atleast 2 elements
    //         long long s2=nums[i]+nums[i+1];
    //         long long temp;
    //         if(turn){ // alice
    //         if(s2 %3==0) temp= getsum(i+2,n,nums,sa+s2,sb,false);
    //         else temp=getsum(i+2,n,nums,sa+s2,sb,true); 
    //     }
    //     else {//bobs turn
    //         if(s2%3==0) temp=getsum(i+2,n,nums,sa,sb+s2,true); //nest turn will be alice
    //         else  temp=getsum(i+2,n,nums,sa,sb+s2,false);
            
    //     }
        
    //       //alice maximixes , bob minmizes 
    //         if(turn){
    //             ans=max(ans,temp);
    //         }
    //         else {
    //             ans=min(ans,temp);
    //         }
    //     }
    //         return ans; //score
        
    
        
        
    // }
    long long maxDifference(vector<int>& nums) {
        //alice starts first 
        //each one  performs actions greedily
        //we will trying to use recursion as there are choices we need to take 
        //choices are leftmost or 2 leftmost 
        int n=nums.size();
        
       // return getsum(0,n,nums,0,0,true); //initially alice satrts  bool turn => if its alice turn true for alice and false for bob

        //DP  - memoization  we will keep teh maximum difference 

        vector<long long>dp(n,LLONG_MIN);
        return getsum(0,nums,dp);
        
       
        
    }
};