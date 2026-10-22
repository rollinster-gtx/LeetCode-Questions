
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for(int i = 0; i < asteroids.size(); i++)
        {
            while(!s.empty() && s.top() > 0 && asteroids[i] < 0
                  && s.top() < -asteroids[i])
            {
                s.pop();
            }

            if(!s.empty() && s.top() > 0 && asteroids[i] < 0
               && s.top() == -asteroids[i])
            {
                s.pop();
            }
            else if(s.empty() || s.top() < 0 || asteroids[i] > 0)
            {
                s.push(asteroids[i]);
            }
        }

        vector<int> ans;

        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
