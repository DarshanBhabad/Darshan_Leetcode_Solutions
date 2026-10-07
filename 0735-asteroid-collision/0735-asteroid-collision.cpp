class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

       // SC =O(n)  TC=O(n) - same item gets pushed and pop once only  also reverse is also O(n)
        //monotonic stack - we maintain only greater than current only  
        //tc=O(n) //as we push and pop each asteroid only once 
        //staright no cycle i.e ex 5 6 -5   -5 to left  , 5 to right 
        //-5 5   will never meet but 5 -5 will 
        int n=asteroids.size();
        stack<int>s;
        for(int i=0;i<n;i++){
            bool destroyed = false;
            while(!s.empty() && s.top()>0 && asteroids[i]<0 ){
                
                if(s.top() < abs(asteroids[i])) { // samller should be popped 
                    s.pop();
                }

                  //equal magnitude curr also gets destoyed 
                else if(s.top() == abs(asteroids[i])) {  //equal magnitude both delete so skip further  while loop  // current gets destroyed and shouldnt be pushed 
                    s.pop();
                    destroyed = true;
                    break;
                }
                 // current smaller than prev presnt so gets destroyed
                 else {  // current gets destoyed by present in stack so shouldnt be psuhed  
                 // so bool destroyed true so in push we check if !destoryed current  then only push it 
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) {
                s.push(asteroids[i]);
            }        
        }
    vector<int>ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
reverse(ans.begin(),ans.end());
    return ans;
    }
};