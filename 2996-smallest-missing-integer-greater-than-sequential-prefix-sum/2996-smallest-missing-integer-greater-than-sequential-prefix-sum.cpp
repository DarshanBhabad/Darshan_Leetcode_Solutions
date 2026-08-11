class Solution {
public:
    int missingInteger(vector<int>& nums) {

        // we only need starting from longest sequence starting from 0;
     int n=nums.size();
    // int fprefsum=0;
     int prefsum=nums[0];
     
        bool seq=true;
       //int maxcnt=0;
       //int cnt=1;
      unordered_set<int>s;
     s.insert(nums[0]);
        for(int i=1;i<n;i++){
            s.insert(nums[i]);
            
            if(nums[i]-nums[i-1]!=1 ){
            //     if(cnt>maxcnt) fprefsum=prefsum;
            //     maxcnt=max(maxcnt,cnt);
            //    // maxpref=max(maxpref,prefsum);
               
                // prefsum=nums[i];
               // seq=false;
            //    cnt=1;
              // continue;
              seq=false;

            } 
            // cnt++;
            if(seq) prefsum+=nums[i];
           
        }
   while(s.find(prefsum) != s.end()) {
    prefsum++;
}
        

        return prefsum;
    }
};