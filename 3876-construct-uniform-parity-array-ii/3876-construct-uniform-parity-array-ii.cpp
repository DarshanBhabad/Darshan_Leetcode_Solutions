class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //we know all odds no problem tyrue
        //all even no problem true
        //but cosist of odd and evens odd can convert the all even to odds by substarting 
        //and we keep all odds same 
        // but with codn nums1[i] - nums1[j] >= 1 so at the even number we  have to make sure there exist an odd which is smaller than him so diffrence will be greater than 1

        // so find smallest even if exist 
        // and find smallest odd if exist and comapare them 
        // if smallest odd exist and it satisfiend smallest even then it will satisfuy all other evens 
     
     int sodd=INT_MAX;
     int seven=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0) {
                seven=min(seven,nums1[i]);
            }
            else{
                sodd=min(sodd,nums1[i]);
            }

        }

        if(sodd!=INT_MAX && seven!=INT_MAX){//there exist both oddsand evens in array
          if(seven-sodd<1) return false;

        }

        return true; //all evens /all odds
    }
};