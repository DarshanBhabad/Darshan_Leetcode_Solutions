class Solution {
public:
    string frequencySort(string s) {
        // vector<int>freq(26,0);//0......25 a....z
        // for(int i=0;i<s.size();i++){
        //     freq[s[i]-'a']++;
        // }
        // priority_queue<int>q;
        // for(int i=0;i<26;i++){
        //     if(freq[i]!=0) q.push(i);

        // }
        int n=s.size();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            //maintains unique keys
            m[s[i]]++;

        }
        priority_queue<pair<int,char>>q;
        for(auto p:m){
            q.push({p.second,p.first}); //freq and char .... priority queue check lexographically first and then second to order
            //push from back

        }
        string ans="";
        //for queue char will be at second
        while(!q.empty()){
            char p=q.top().second;
            int m=q.top().first;
          while(m>0) {
          ans+=p;
          m--;
          }
          q.pop(); //pop from front
        }

return ans;
        
    }
};