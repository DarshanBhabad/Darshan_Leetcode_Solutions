class Solution {
public:

    //TC =(nlogn + ndlogd)  sc=o(n)
int getbig(int n){
    string s=to_string(n);
    sort(s.rbegin(),s.rend());//sort in des order

    return stoi(s);
    
}
    
    long long maximizeSum(vector<int>& nums, int k) {
     int n=nums.size();
        sort(nums.begin(),nums.end()); //sor in ascending oder
        // we have to find the max possible sum so we have to change the positions of  digits of biggeer numbers of nums which will be at last ;
        
        int i=n-1;
        long long sum=0;
//gain calculateion 
        vector<pair<int,int>>gain;
        for(int i=0;i<n;i++){
            int m=getbig(nums[i]);
            gain.push_back({m-nums[i],i});
            sum+=nums[i];
        }
        sort(gain.rbegin(),gain.rend()); //desc ofder of gain 
        for(int i=0;i<min(k,n);i++){//add maximized gain of only k's
            if(gain[i].first>0) sum+=gain[i].first;
            else break;  // as gain is 0 and we have sorted so further willl also be less reduce the sum
            
        }

        // it wll not work for ex 19,28    k=1   91 should be selected so calcute the gain 
        
        // while(k>0 && i>=0){ //both condn must hold
        //       //maximum ddigit forming from these digit 
        //     // reduxe k only if digit formed is greater than original els epreserve it for next 
        //     int m=getbig(nums[i]);
        //     if(m>nums[i]){
        //         nums[i]=m;
        //         k--;
        //     } 
        //     sum+=nums[i];
        //     i--;
        // }
       
        // while(i>=0) {
        //      sum+=nums[i];
        //     i--;
        // } 
         return sum;
    }
};