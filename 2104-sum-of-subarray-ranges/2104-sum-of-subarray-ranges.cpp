class Solution {
public:
// TC =O(n) and SC =O(n);
void getprevsm(vector<int>&prevsm,vector<int>&nums,int n){
   stack<int>s;
  for(int i=0;i<n;i++){
       while(!s.empty()&& nums[s.top()]>=nums[i]){
        s.pop();
       }
       if(s.empty()) prevsm[i]=-1; //no prev small founded 
       else prevsm[i]=s.top();
       s.push(i);
  }


}
void getnextsmall(vector<int>&nextsmall,vector<int>&nums,int n){
 stack<int>s; //>= not used to solve overlapp betn prevsmall and getnext in case ex= 1,1 
 // needed subarrays will be 3 but >= will give 4   to handle duplicates  
 for(int i=n-1;i>=0;i--){
       while(!s.empty()&& nums[s.top()]>nums[i]){
        s.pop();
       }
       if(s.empty()) nextsmall[i]=n; //no next small founded so  right will  get all elements  so set n 
       // so that n-i = right
       else nextsmall[i]=s.top();
       s.push(i);
  }

}
void getprevgreater(vector<int>&prevgreater,vector<int>&nums,int n){
    stack<int>s;
  for(int i=0;i<n;i++){
       while(!s.empty()&& nums[s.top()]<=nums[i]){
        s.pop();
       }
       if(s.empty()) prevgreater[i]=-1; //no prev small founded 
       else prevgreater[i]=s.top();
       s.push(i);
  }

}
void getnextgreater(vector<int>&nextgreater,vector<int>&nums,int n){
stack<int>s;
  for(int i=n-1;i>=0;i--){
       while(!s.empty()&& nums[s.top()]<nums[i]){  
        //IMP
        // If you use >= in both helpers, equal elements can be counted more than once. If you use > in both, some subarrays can also be counted more than once.
//so >= and > and <= and <

        //just < to handle duplicates ex 1,1,1 
       // contribution of 1 as 1,1,1 counted only once in greater contriburtion functions 
        s.pop();
       }
       if(s.empty()) nextgreater[i]=n; //no prev small founded 
       else nextgreater[i]=s.top();
       s.push(i);
  }

}

    long long subArrayRanges(vector<int>& nums) {
        //brute for n2 run two loops maintain me , mine  and at each subarray cnt difference
        //just like sum of subarray minimums here we will find the contribution of each element as largest ele and as smallest element both 
        // after than we will add all largest ele contri and  subs smallest ele contri 
int n= nums.size();
vector<int>prevsm(n);
vector<int>nextsmall(n);
vector<int>prevgreater(n);
vector<int>nextgreater(n);

getprevsm(prevsm,nums,n);
getnextsmall(nextsmall,nums,n);
getprevgreater(prevgreater,nums,n);
getnextgreater(nextgreater,nums,n);


// int mod=1e9+7;
long long  ans=0;
        for(int i=0;i<n;i++){
            int left= i - prevsm[i]; //it will be smallest until its prev small 
            int right= nextsmall[i]-i;
            //total subarray = left* right   and contri of element = l*r*nums[i]
            int left2=i-prevgreater[i];
            int right2=nextgreater[i]-i;

      ans=ans+left2*right2*1LL*nums[i]; //adding contributions as largest 
      ans=ans-left*right*1LL*nums[i]; //removing contributions as ssmallest 
      


        }

        return ans;
    }
};