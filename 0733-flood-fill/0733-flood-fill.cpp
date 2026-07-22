class Solution {
public:
int m;
int n;
void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<bool>>& visited,int e){
    //starting node image[sr][sc]
    // if(image[sr][sc]!=e) return;
    visited[sr][sc]=true;
    image[sr][sc] = color;
    if(check(sr,sc-1,m,n,e,image,visited))  dfs(image,sr,sc-1,color,visited,e);
     if(check(sr,sc+1,m,n,e,image,visited))   dfs(image,sr,sc+1,color,visited,e);
      if(check(sr-1,sc,m,n,e,image,visited))  dfs(image,sr-1,sc,color,visited,e);
       if(check(sr+1,sc,m,n,e,image,visited))  dfs(image,sr+1,sc,color,visited,e);
return;
}
bool check(int i,int j,int m,int n,int e,vector<vector<int>>& image,vector<vector<bool>>& visited){
    if(i>m-1||i<0||j>n-1||j<0||image[i][j]!=e||visited[i][j]) return false;
    return true;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //using DFS
     m=image.size();
     n=image[0].size();
        int e=image[sr][sc];
        vector<vector<bool>> visited(m, vector<bool>(n, false));
         dfs(image,sr,sc,color,visited,e);

          return image;
    }
};