class Solution {
public:

//Optimal sliding window using 2 ptrs TC=O(n)... SC=O(n)
int numberOfSubstrings(string s) {
 // instaed of sounting for each substring
 //ex abcabc we can see that once the substring becomes valid it will be valid for all substrings of 
 // size greater than 1st valid substr...  for abcabc  for substr with 'a' start .... 1st valid at c inx=2;
 // we can see that all after abc i.e abca, abcab, abcabc  valid .... 
 // and thier count can be calculated by n-right (1st valid)

 unordered_map<char,int>m;
 int n=s.size();
int count=0;
int left=0;
// window left.....Right   //left will be the one which will  mark start of substr
 for(int right=0;right<n;right++){
    m[s[right]]++;

    while(m['a']>0 && m['b']>0 && m['c']>0){  // aabca   1st valid for 1st 'a'  at 'c' idx=3 cnt and
    // shrink as for 2nd 'a' at sane right we get valid window so add count 
        count+=n-right;
        m[s[left]]--;
        left++;

    }

 }









return count;
    }
};

            //        //BRUTE FORCE TC = O(n3) SC=O(n)
// class Solution {
// public:

// bool checkabc(string s,int i,int j){
//     int cnta=0;
//     int cntb=0;
//     int cntc=0;
//     for(int k=i;k<=j;k++){
//              if(s[k]=='a') cnta++;
//              if(s[k]=='b') cntb++;
//              if(s[k]=='c') cntc++;
//     }
//     if(cnta<1||cntb<1||cntc<1) return false;
//     return true;

// }
//     int numberOfSubstrings(string s) {

        
//   int n=s.size();
//        int count=0;
//        for(int i=0;i<n;i++){
//         for(int j=i+2;j<n;j++){  //for abc to exist atleast start from 3 places 
//                if(checkabc(s,i,j)) count++;

//         }
//        }
//         return count;
//     }
// };
  
