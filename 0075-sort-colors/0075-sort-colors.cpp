class Solution {
public:
    void sortColors(vector<int>& nums) {
        //BUbble sort 
       //option 2
        int count0=0,count1=0,count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)count0++;
            else{
                (nums[i]==1)?count1++:count2++;
            }
        }
        int i=0;
        while(i<nums.size()){
            if(count0){ // i.e if cnto is > 0
                nums[i]=0;
                count0--;
            }
            else if (count1){
                nums[i]=1;
                count1--;
            }
            else{
                nums[i]=2;
                count2--;
            }
            i++;
        }
    }
};