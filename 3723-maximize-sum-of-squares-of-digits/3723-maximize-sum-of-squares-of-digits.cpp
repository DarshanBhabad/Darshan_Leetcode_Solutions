class Solution {
public:
//OPTIMAL TC= O(nums)
    string maxSumOfSquares(int num, int sum) {
            if(sum>num*9) return ""; //it is impossible to reach to sum 
            // maximum num digit number will be 9999 nums time summation is 9*num if sum>9*num we can't reach there 

        //GREEDY APPORACH at each step design the greatesyt number from left to right L->R
        string ans ="";
        for(int i=0;i<num;i++){ //we need num size number 
           int digit= min(9,sum);  //sum=12 max digit we can place 9 
           ans+=to_string(digit);
           sum-=digit; // 12-9=3 

           

        }
        return ans;
    }
};


//BRUTE FORCE TC= Time complexity: (num * 10^{num})
// class Solution {
// public:
// 
// bool calsum(int n,int sum){ //calcultate sum of digits 
// int ts=0;
//        while(n!=0){
//           ts+=n%10;
//           n=n/10;
//        }
//        if(ts==sum) return true;
//        return false;
// }
//     string maxSumOfSquares(int num, int sum) {
//         //0 is whole number neithe rpositive nor negative 
//         int  se=1; //smallest num digit number 
//         while(num>1){
//             se=se*10;
//             num--;
//         }
//     int  me=se*10 ; //to get max bndery

// int ans=INT_MIN;
//         for(int i=se;i<me;i++){ //all num digit numbers 
//              if(calsum(i,sum)) ans=max(i,ans);
//         }
//         if(ans==INT_MIN) return "";
//         string a;
//         a=to_string(ans); //to convert to string
//         return a;
//     }
// };