class Solution {
public:
    // bool check(vector<int>& nums, int i, int j,int a, int b){
    //     int e=0;
    //     int o=0;
    //     for(int k=i;k<=j;k++){
    //         if(nums[k]%2==0) e++;
    //            else o++;
    //     }
    //      if(o == 0) return false;
    //      return 1LL * e * b <= 1LL * o * a;
    // }
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int e=0;int o=0;
            for(int j=i;j<n;j++){
               // if(check(nums,i,j,a,b)) cnt++;
                 if(nums[j] % 2 == 0)
                  e++;
                 else
                   o++;

                if(o > 0 && 1LL * e * b <= 1LL * o * a)//cross  mp
                     cnt++;
            }
        }

        return cnt;
    }
};