class Solution {
public:
    bool isNegative(const int& num) { return num < 0; }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result {asteroids[0]};

        for (int i = 1; i < asteroids.size(); ++i) {
            bool breaked = false;
            while (!result.empty() && isNegative(asteroids[i]) && !isNegative(result.back())) {
                if (abs(asteroids[i]) > abs(result.back())) result.pop_back();
                else if (abs(asteroids[i]) == abs(result.back())) {
                    result.pop_back();
                    breaked = true;
                    break;
                }
                else {
                    breaked = true;
                    break;
                }
            }
            if (!breaked) result.push_back(asteroids[i]);
        }
        return result;
    }
};