class DSU{
    //O(N² α(N)) === N2 for outer 2 for loops and find takes amortized α(N)
    public:
    vector<int>parent;
    vector<int>rank;

    //constructor
    DSU(int n){
        parent.resize(n); // agfter getting n make parent vector of siz en
        rank.resize(n,0); // initialize with 0;

        for(int i=0;i<n;i++){
            parent[i]=i; // initially itself is parent 
        }
    }

void unionby( int u, int v){ // merge two sets 
   int paru=find(u); // get the parents 
   int parv=find(v);
 if(paru==parv) return; // no merge needed 
 
 if(rank[paru]==rank[parv]){
    parent[parv]=paru;
    rank[paru]++;
 }
 else if(rank[paru]>rank[parv]){
    parent[parv]=paru;
   
 }
 else parent[paru]=parv; // paru rank was less so it gets merged with parv
 

}

int find(int x){ //find parent 
//BC
   if(parent[x]==x) return x; // we reach the root parent it itself is its parent 
   //else recursion 
   // path compression 
   return parent[x]=find(parent[x]);

}


};



class Solution {
public:


int findCircleNum(vector<vector<int>>& isConnected) {
// USING DISJOINT SET UNION  TC= constant O(1) - find union
// to return final count of provinces just retunr the number of unique parents 

// initially let the comopnents be n i.e max prbvinces = no of cities =n;
int n=isConnected.size();
int compo=n;
DSU dsu(n); // object of DSU to use properties and fucntions 
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){ // as  oif i==j boths parent same no neeed to take also j < current i+1
    // alredy inserted in set  i.e for for i=2   0 and 1 alredy done when i=0 , j=1,2,3,4,5 
    // i=1 j=2,3,4 bcoz j=0 alredy happned when i=0  and j=1 (no need same root )
        if(isConnected[i][j]==1){ // i.e there is reln so they should be unionized only if they alredy not i.e thrie parent is different 
        // to find parent use find func 
           if(dsu.find(i)!=dsu.find(j)){
            dsu.unionby(i,j); // merge them 
            compo--; // as merged  max provinces decraesed 
           }
           

        } 

    }
}

return compo;

}
};



// // TC= O(V+E) TC of DFS


// void DFS(int u, vector<list<int>>& G , vector<bool>& visited){
//     visited[u]=true;
//     for(int v: G[u]){
//         if(!visited[v]) DFS(v,G,visited);
//     }
// return;
// }
//     int findCircleNum(vector<vector<int>>& isConnected) {

//         // we just need to find the edges in connected graph 
//         // hence cities are vertices now all cities in connected graph represent sing province 


      
//       // its an n*n matrix 
//       // so there will be total n cities 
//        int n= isConnected.size(); // total rows which will be eq to cols also 
      
   

//       // BUILD GRAPG first 
//       vector<list<int>>G(n);
//       for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){ 
//             if(i!=j && isConnected[i][j]==1){
//                 G[i].push_back(j);

//             }
//         }
//       }

// // now whole builded graph we get 

// vector<bool>visited(n,false);
// int cnt=0;
// for(int i=0;i<n;i++){
//     if(!visited[i]){
//         cnt++; // each DFS call from here tarverse one connected group of cities i.e province;
//         DFS(i,G,visited);
//     }
// }

//     return cnt;
        
//     }
// };