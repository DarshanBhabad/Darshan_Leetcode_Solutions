class Solution {
public:

// Tc = O(n+m)logn Sc= O(n+m)
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        //SERVERSRS PRIORITY QUEUE WITH WT AND ALSO CONDITION FOR TIE 
        // customization 
        // make servers visible after cooldown 

        int n=servers.size();
        int m=tasks.size();
        //wt +index as we neeed to resolve tie also 
        //min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<n;i++){
             q.push({servers[i],i});
        }
vector<int>ans;
priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>>p;//same size as no of servers to ahndle cooldown time and again put back again in main queue   // pair,cooldown time
long long j=0;  //current time

        for(int i=0 ;i<m;i++){
            //check cooldown queue has anything we need to push in main queue
//             1. Why j = max(j, i)?
// i is the task index, which also represents its arrival time.
// But j can be larger than i if we had to wait for a server.

              j = max(j, 1LL * i);//i=4 but server becomes available at 8 which marked by j
            while(!p.empty()&&p.top().first<=j){
                 q.push(p.top().second); //push server pair
                 p.pop();

                    
            }

            if(q.empty()) { //if no server is availble
                j = p.top().first; //earliest servers availbe time 

                while(!p.empty() && p.top().first <= j) {
                    q.push(p.top().second);
                    p.pop();
                }
            }

            
            auto c= q.top(); //pq but function name are as stack 
            ans.push_back(c.second);
            q.pop();
            p.push({j+tasks[i],c});
            //we need to push server again once its cooldown finished 
          
            
        }
        return ans;
    }
};