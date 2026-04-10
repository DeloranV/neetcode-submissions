class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        auto comp = [](const vector<float>& p1, const vector<float>& p2) {
            return p1[0] > p2[0];
        };
        
        priority_queue<vector<float>, vector<vector<float>>, decltype(comp)> min_heap;
        for (auto& point : points) {
            float dist_sq = (point[0] * point[0]) + (point[1] * point[1]);
            min_heap.push({dist_sq, point[0], point[1]});
        }

        while (k--) {
            auto point = min_heap.top();
            min_heap.pop();
            result.push_back({point[1], point[2]});
        }

        return result;
    }
};
