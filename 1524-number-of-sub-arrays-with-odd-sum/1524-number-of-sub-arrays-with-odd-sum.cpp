class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       // prefix sum 

//        For any subarray [i...j]:
// \[
// sum(i,j)=prefix[j]-prefix[i-1]
// \]

// A subarray has an odd sum when its two prefix sums have different parity.

// Why?
// - Odd − Even = Odd
// - Even − Odd = Odd
// - Odd − Odd = Even
// - Even − Even = Even
//Therefore, we only need to count how many previous prefix sums are odd and even.
       int mod = 1e9 + 7;
     long long odd=0;
     long long  even=1; //initially for 1st elemnt prefix sum is 0 which is even 
     long long  sum=0;
     long long  ans=0;
     for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum%2==0){//sum  is even
           //adding current element                                                                                          
           ans=(ans+odd)%mod; 
           // all odd subarrays with these ending becomes even 
           even++; 
           

        }
        else{
            ans=(ans+even)%mod;
            odd++;
        }
     }

return ans;










   //optimal we will find subarrays ending with current index dp like solution 
   // track how many of them are odd
//    int mod = 1e9 + 7;

//         long long odd = 0;
//         long long even = 0;

//         long long ans = 0;

//         for(int i = 0; i < arr.size(); i++) {

//             long long newOdd, newEven;

//             if(arr[i] % 2 != 0) {
//                 newOdd = even + 1;
//                 newEven = odd;
//             }
//             else {
//                 newOdd = odd;
//                 newEven = even + 1;
//             }

//             odd = newOdd % mod;
//             even = newEven % mod;

//             ans = (ans + odd) % mod;
//         }

//         return ans;
//    We are not generating every subarray.

// Instead, at each index, we ask:
// 1. How many odd-sum subarrays ended at the previous index?
// 2. How many even-sum subarrays ended at the previous index?
// 3. After adding the current element, how many become odd and how many become even?
// we just maintain count or parity of subarrays 


// odd: Number of odd-sum subarrays ending at the previous index.
// even: Number of even-sum subarrays ending at the previous index.








    //     //we know odd+odd=even 
    //     // even +even=even
    //     // odd+ even =odd;



    //   //   //BRUTE FORCE
    //     int cnt=0;
    //     int mod=1e9+7; 
    //     int n=arr.size();
    //     for(int i=0;i<n;i++){
    //         int sum=0;
    //         for(int j=i;j<n;j++){
    //             sum+=arr[j];
    //             if(sum%2!=0)cnt++;
    //             cnt=cnt%mod;
    //         }
    //     }
    //     return cnt;
    }
};