class Solution {
public:
bool dfscyclecheck(int u,vector<bool>& visited, vector<list<int>>& g, vector<bool>& recpath,stack<int>& s){
    visited[u]=true;
    recpath[u]=true;
    for(int v:g[u])//for each neigh of u
    {
        if(!visited[v]){
           if(dfscyclecheck(v,visited,g,recpath,s)) return true;
           
        }
        //visited and in rec path
        else if(recpath[v]) return true; // visited and in curr nodes recpath
     
    }
    s.push(u);
    recpath[u]=false; //backtrack;

    return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // here you have to use topological sort + cycle dectection in DAG
        //we know that if cycle not detected then only topo sort so print stack tat time only 

        vector<bool>visited(numCourses,false);
        vector<list<int>>g(numCourses);
       // p=[1,0] b=0  should take 1st so 1 is depend on 0 so edge direction (dependency)=  b->a;
        for(auto p: prerequisites){
           g[p[1]].push_back(p[0]);

        } // graph built successfully
         //to store topological order 
        stack<int>s;
        vector<bool> recpath(numCourses, false); //set only once bcoz backtracking indfscyclecheck will set it to original again
        for(int i=0;i<numCourses;i++){ //consider disconnected /multiple components
           if(!visited[i]){
           if(dfscyclecheck(i,visited,g,recpath,s)) return {};//empty array

            

           }

        }
 vector<int>ans;
 while(!s.empty()){
    ans.push_back(s.top());
    s.pop();
 }
        return ans;
    }
};