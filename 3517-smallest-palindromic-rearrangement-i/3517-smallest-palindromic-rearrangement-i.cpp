class Solution {
public:
    string smallestPalindrome(string s) {
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
    }
};