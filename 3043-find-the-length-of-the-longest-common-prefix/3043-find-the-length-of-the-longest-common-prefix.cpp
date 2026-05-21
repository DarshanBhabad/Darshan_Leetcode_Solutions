class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>s;
        for(int i=0;i<arr1.size();i++){
           
            string  p =to_string(arr1[i]);
            int j=0;
            while(j<p.size()){
                s.insert(p.substr(0, j+1));  //substring from 0 to j = substr(0, j+1)
                j++;
            }

        }
 int maxc=0;
        for(int i=0;i<arr2.size();i++){
            int currc=0;
             string  q =to_string(arr2[i]);
            int j=0;
            while(j<q.size()){
                if(s.find(q.substr(0, j+1))!=s.end()){
                    currc++;
                }
                else{
                    break;
                }
                j++;
            }
            maxc=max(maxc,currc);

        }
        return maxc;
    }
};