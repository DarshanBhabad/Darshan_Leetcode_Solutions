class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      //O(n)
      int n=nums.size();
      unordered_set<int>s; //ordered set also takes nlogn so unordered set  both stored  uynique appearnces ;
      //handles duplication 
      if(n==0) return 0;
      for(int i=0;i<n;i++){
        s.insert(nums[i]); //O(1)
      }
      int ans=1;
      int c;
      for(int e:s){
        c=1;
        int t=e+1;
         // Start only from the beginning of a sequence
         if(s.find(e-1)==s.end()){ // as we traversing set one by one elements for ex [100,4,200,1,3,2]
          //for ele 1 we e=alredy counted 2,3,4  so when we go to 2,3 or 4 we just check if prev number exist for it as it will be the only one we who will count them
          //iterate only from seq start
          while(s.find(t)!=s.end()){
            c++;
            
            t=t+1;
            
          }
         }
      ans=max(ans,c);
      }


return ans;



        // //o(nlogn)
        //   int n=nums.size();
        //   if(n==0) return 0;
        // sort(nums.begin(),nums.end());
        // int ans=1;
        // int cnt=1;
        // //handle duplicates 
        // for(int i=1;i<n;i++){
        //        if(nums[i]-nums[i-1]==1) cnt++;
        //        else if(nums[i]==nums[i-1]) continue; //dont change or ereset count
        //        else{
               
        //         cnt=1;
        //        } 
        //        ans=max(ans,cnt);
        // }
        
        // return ans;
    }
};