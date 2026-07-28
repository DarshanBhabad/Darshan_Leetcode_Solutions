class Solution {
public:
    string smallestPalindrome(string s) {
// TC General case: O(n log k) logn tc of insertion /upfdate in map
//if there are only Lowercase English letters: O(n)


        int n=s.size();
       // if(n==1) return s;
       map<char,int>m;  //stores charcters lexo a,b,c .. keys    
      // ex= aabb

       for(int i=0;i<n;i++){
        m[s[i]]++; //chracters frequency
       }

       //only the middle one in odd size string will have odd frequency
char odd = '\0'; //null char for string s=""
//int odfrq=0;
string ans="";
       for(auto p:m){
        int k=p.second;
        char c=p.first;
        
            int i=1;
            while(i<=k/2){
                ans+=c;
                i++;
            }
    
        if(k%2==1){  // store odd freq char which will be only one
        odd = c;
        }

        }
        
            
        
       
// for handling the double occurnce if length is odd for odd c store ans size then update ans
string firsthalf= ans;
      if(odd != '\0')  ans += odd;  //extra copy of the odd freq charc at the end of ans 
  for(int i=firsthalf.size()-1;i>=0;i--)//copy elements of 1st half in rev order
  {
    ans+=firsthalf[i];
  }
  return ans;


  // APPROACH 2 no logn 
//    string smallestPalindrome(string s) {
//         if (s.length() == 1) return s;
        
//         vector<int> frequency(26, 0);
//         for (char c : s) frequency[c - 'a']++;

//         int left = 0, right = s.length() - 1;
//buliding from end and st simultaneously as it is palindromic
//         for (int i = 0; i < 26; i++) {
//             while (frequency[i] >= 2) {
//                 s[left] = i + 'a';
//                 s[right] = i + 'a';
//                 left++;
//                 right--;
//                 frequency[i] -= 2; 
//             }
//         }
        // odd count then that extra odd should be added at the updated left 
//         if (s.length() % 2 != 0) {
//             for (int i = 0; i < 26; i++) {
//                 if (frequency[i] == 1) {
//                     s[left] = i + 'a';
//                     break;
//                 }
//             }
//         }

//         return s;
//     }
// };
    }
};