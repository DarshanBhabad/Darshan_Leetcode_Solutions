class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long currmass=mass;
        for(int i=0;i<asteroids.size();i++){
        if(asteroids[i]>currmass) return false;
        currmass+=asteroids[i];

        }
        return true;
    }
};