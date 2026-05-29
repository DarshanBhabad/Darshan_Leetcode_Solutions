class Solution {
public:
int digit_sum(int digit){
    int sum=0;
    while(digit!=0){
        int rem=digit%10;
        sum+=rem;
        digit/=10;

    }
    return sum;

}
    int minElement(vector<int>& nums) {
        int mins=INT_MAX;
        for(int i=0; i<nums.size();i++){
            mins=min(mins,digit_sum(nums[i]));

        }
        
        return mins;
    }
};