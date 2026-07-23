class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

// O(1) (the loop runs at most about 17 times since n ≤ 10^5)

// n = 4

// Numbers

// 1 2 3 4

// Unique XORs become

// 0..7

// Size

// 8 = 2³
// n = 5

// Again

// 0..7

// Answer

// 8
// n = 8

// Numbers

// 1...8

// Unique XORs become

// 0..15

// Answer

// 16 = 2⁴

// A pattern appears.
      int n = nums.size();

        if (n < 3)
            return n;

        int bits = 0;
        while ((1 << bits) <= n)
            bits++;

        return 1 << bits;


        //O(n3)

        
    //     int n=nums.size();
    //     // int cnt=nums.size();
    //     // for unique xor tripletes u need to have unique numbers 
    //     // exception all numbers are same 111 will give =1 , 122 xor =1 
    //     // so to handle same idx cases  111 ,222,122,133.... we initialized cnt with nums.size
    //     //now just calculate how many 3 unique numbers triplets we can form
    //     //for that we need to find combinations of 3 from all given numbers so do nc3 but it
    //     // will face the problem od duplicate XOR's 
    //     if(n>=3){
    //     // nc3 = n!/(n-r)!r! = (n)(n-1)(n-2)(n-3)!/(n-3)! *3!=n*(n-1)*(n-2)/6;
    //     // cnt+=n*(n-1)*(n-2)/6;
    //     unordered_set<int>s;
    //     // unordered_set<int> s;

    //  for(int x:nums)
    //      s.insert(x); //all n numbers instead of using cnt variable // int cnt=nums.size();


    //     for(int i=0 ; i<=n-3;i++){
    //         int j=i+1;
    //         while(j<=n-2){
    //        int k=j+1;
    //        while(k<n){
    //         int cxor=nums[i] ^ nums[j] ^ nums[k];
    //         if(s.find(cxor)==s.end()){
    //             s.insert(cxor);
                
                
    //         }
    //         k++;
    //        }
    //        j++;
    //         }
    //     }



    //     }
    //     return s.size();
        
    }
};