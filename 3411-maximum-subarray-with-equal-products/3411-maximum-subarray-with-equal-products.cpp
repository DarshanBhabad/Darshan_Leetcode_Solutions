class Solution {
public:
    int maxLength(vector<int>& nums) {
        
        //
        int g=nums[0];
        int l=nums[0];
        int n=nums.size();
        // for(int i=1;i<n;i++){
        //    g=gcd(g,nums[i]);
        //    l=lcm(l,nums[i]);
        // }
        int s=g*l;
        //two pointr; sliding window
        int i=0; 
        int  j=0;
        int ans=0;
        int prod=1;
        // while(j<n){
        //        prod*=nums[j];
        //        while(prod!=s && i<j){//shirnk window
        //          prod/=nums[i];
        //         i++;
        //        }
        //        if(prod==s) ans=max(ans,j-i+1);

        //        j++;
        // }
        for(int i=0;i<n;i++){
            int g;
            int l;
             double  prod=1;
            for(int j=i;j<n;j++){
                prod*=nums[j];
                if(j==i){
                    g=nums[i];
                    l=nums[i];
                }
                else{
                    g=gcd(g,nums[j]);
                    l=lcm(l,nums[j]);
                }
                      if(prod==g*l) ans=max(ans,j-i+1);
            }

        }
        return ans;

//         class Solution {
// public:
//     int maxLength(vector<int>& nums) {
//         int n=nums.size();
//         int maxi=INT_MIN;
//         for(int i=0;i<n;i++){
//             long long pro=1,g=0,l=1,maxLcm = 100000000000;;
//             for(int j=i;j<n;j++){
//                 pro *=nums[j];
//                 if(pro > maxLcm) break;
//                 g=gcd(g,nums[j]);
//                 l=lcm(l,nums[j]);
//                 if(pro== g*l) maxi=max(maxi,j-i+1);
//             } 
//         }
//         return maxi;
//     }
// };
    }
};