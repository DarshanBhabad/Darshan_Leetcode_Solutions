class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        //TC=O(1)....sc=O(n)..ans vec

       vector<int>ans;
       string s="123456789"; //universal swq string

       for(int len=2;len<=9;len++){ // 10 to 10^9 2 digit to 9 digit

       for(int i=0;i+len<=9;i++){//start from each digit i.t 1 2 3 4 5 ... for len= 12 23 .....89....123...789 ...now len=4 i=0 4 digit seq  1234 2345 .....
       int num=stoi(s.substr(i,len)); //string to int  //substr(i,j) =i=st idx j=size from i
       if(num>=low && num<=high)ans.push_back(num);      
       }     
        }

return ans;

    }
};
        //BRUTE FORCE
//         class Solution {
// public:

// bool checkseq(string s){
    
//     for(int i=1;i<s.size();i++){
//         if((s[i]-'0')-(s[i-1]-'0')!=1) return false;

//     }
    
// return true;
// }
// vector<int> sequentialDigits(int low, int high) {
        
//   vector<int>ans;
//         for(int i=low;i<=high;i++){
//           string p=to_string(i);
//            if(p.size()==1  || checkseq(p)) ans.push_back(i);

//         }

//         return ans;
//     }
// };
        
