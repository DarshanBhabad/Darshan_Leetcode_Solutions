class Solution {
public:
    int maxNumberOfBalloons(string text) {
     unordered_map<char,int>m;
     for(char c : text) {
            if(c=='b' || c=='a' || c=='l' || c=='o' || c=='n')
                m[c]++;
        }
// string b="balloon"
    return min({
            m['b'],
            m['a'],
            m['n'],
            m['l'] / 2,
            m['o'] / 2
        });  //list 
        // suppose any letter isnt there in text ex. m['o'] will auto create entry and will have freq 0 
    // so min 0 will return 

    // as we need l and o twice as others make sure we do /2  so b=1 but l=1 also then 1/2 =0 
    //and b= 2 l=3  then 3/2 =1.5 in int =1   so only 1 pair of ballon
        
    }
};