class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() < 2) return 1;
        vector<pair<int, int>> pos_spd;
        int fleet_counter = position.size();

        for (int i {0}; i < position.size(); ++i) {
            pos_spd.push_back({position[i], speed[i]});
        }
        sort(pos_spd.begin(), pos_spd.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        });
        
        float running_max = 0.0;
        for (auto& car : pos_spd) {
            float delta_target = (float)(target - car.first) / car.second;
            cout << delta_target << endl;
            if (running_max != 0 && delta_target <= running_max) fleet_counter--;
            else running_max = delta_target;
        }
        return fleet_counter;
    }
};
