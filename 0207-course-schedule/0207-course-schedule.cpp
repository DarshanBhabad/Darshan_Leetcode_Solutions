class Solution {
public:
 
 bool dfscycle(int src,vector<bool>& vis,vector<list<int>>& G,vector<bool>& recpath){
   vis[src]=true;
   recpath[src]=true;

   for(int v:G[src]){
    if(!vis[v]){
        if(dfscycle(v,vis,G,recpath)) return true;
       
    }
     else if(recpath[v]) return true;
    
    
   }
   recpath[src]=false;//backtracking
    
return false;
 }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //prerequisites are the graph eges , graph is acyclic and directed 
        //use top[logical sorting 
        //[ai,bi]= bi->ai  ai is dependnd on bi so bi is depenent of ai

        //check cycle in directed graph using dfs if cycle exist topological ordering not possible : return false

        vector<bool>vis(numCourses,false);
        // stack<int>s;

        vector<list<int>>G(numCourses); //graph
        for(auto p:prerequisites){
            G[p[1]].push_back(p[0]); //[ai,bi] ---bi->ai
            
        }
vector<bool> recpath(numCourses, false); //declared once becoz  it automatically becomes empty or set false once we complete func call
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){              
                if(dfscycle(i,vis,G,recpath)) return false; //cycle detected

            }
        }
return true; 


// BFS TOPOLOGICAL SORT : cycle detection in directe dgraphs : Kahn's algo
// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int>inDegree(numCourses,0);
//         vector<vector<int>>adj(numCourses);
//         for(int i=0;i<prerequisites.size();i++){
//             adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
//             inDegree[prerequisites[i][0]]++;
//         }
//         queue<int>q;
//         for(int i=0;i<numCourses;i++){
//             if(inDegree[i]==0)
//             q.push(i);
//         }
//         int cnt=0;
//         while(!q.empty()){
//             auto node=q.front();
//             q.pop();
//             cnt++;
//             for(auto it:adj[node]){
//                 inDegree[it]--;
//                 if(inDegree[it]==0) q.push(it);
//             }
//         }
//         if(cnt==numCourses) return true;
//         else return false;
//     }
// };
    }
};