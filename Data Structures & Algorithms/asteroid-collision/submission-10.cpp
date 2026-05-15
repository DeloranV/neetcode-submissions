class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> asteroid_stack;

        for (auto& a : asteroids) {
            bool breaked = false;
            if (!asteroid_stack.empty()) {
                while (!breaked && asteroid_stack.back() > 0 && a < 0) {
                    if (abs(asteroid_stack.back()) < abs(a)) asteroid_stack.pop_back();
                    else if (abs(asteroid_stack.back()) == abs(a)) {
                        asteroid_stack.pop_back();
                        breaked = true;
                    }
                    else breaked = true;
                }
            }
            if (!breaked) asteroid_stack.push_back(a);
        }
        return asteroid_stack;
    }
};