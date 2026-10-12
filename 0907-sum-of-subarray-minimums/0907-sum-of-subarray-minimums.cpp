class Solution {
public:
void prevsmalleridx(vector<int>& arr,vector<int>& psidx,int n){
    stack<int>s;
    //as 1st elemt ahs no smaller stack is empty or elemnt didnt get any smaller we put -1 there 
    for(int i=0;i<n;i++ ){
        while(!s.empty() && arr[s.top()]>=arr[i]){
            s.pop();

        }
        if(s.empty()) psidx[i]=-1;
        else psidx[i]=s.top();
        s.push(i);
    }
}

void nextsmalleridx(vector<int>& arr,vector<int>&nsidx,int n){
     stack<int>s;
     
    //as last elemt ahs no smaller stack is empty or elemnt didnt get any smaller we put n there 
    for(int i=n-1;i>=0;i-- ){
        while(!s.empty() && arr[s.top()]>arr[i]){ // not >= to handle duplicate elements ex arr=1,1 
        // it will give 1,1 twice we need only once like for 1st one 2 contribution and for 2nd 1 two contributions so count only one prev 4  after > 3  ... 1,1,(1,1)
            s.pop();

        }
        if(s.empty()) nsidx[i]=n;
        else nsidx[i]=s.top();
        s.push(i);
    }

}


    int sumSubarrayMins(vector<int>& arr) {
 // optimization - fining the individual contribution of each elemnt in the ans or sum 
 // if 1 is contributing 5 time then 1*5 
 // so we broken down the problem to find the individual contribution of each ele in ans/sum
 // next smaller , prev smaller
 //watch strivers video

 //TC=O(n) sc=O(n)
int sum=0;
int mod=1e9+7;
int n=arr.size();
vector<int>psidx(n);
vector<int>nsidx(n);
prevsmalleridx(arr,psidx,n);
nextsmalleridx(arr,nsidx,n);

 for(int i=0;i<n;i++){
   int left=i-psidx[i]; //left side elemnts greater than nums[i]
   int right= nsidx[i]-i;  //to calculate the right side elemnts graeter than[i]
   // contribution total subarrays where thes enums[i] will be minimum is formed through these left and right so  subarrays = left*right
   sum=(sum+(left*right*1LL*arr[i])%mod)%mod; // take mode at each step 1LL because multiplictaion can be larger 


 }
return sum;









        // //no  of possible subarrays with array of size n is n*(n+1)/2
        // // with size k is n-k+1
        // // monotonic stack w emaintain min elemnt in satck

        // //BRUTE FORCE O(n2) O(1)
        // int mod=1e9+7;
        // int ans=0;
        // int n=arr.size();
        
        // for(int i=0;i<n;i++){
        //     int me=arr[i];
        //     for(int j=i;j<n;j++){ // all subarrays 
        //     me=min(me,arr[j]); // protects min elemnt
        //     ans=(ans+me) % mod;
        //     }
        // }
        // return ans;
    }
};