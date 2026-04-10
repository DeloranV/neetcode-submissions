class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
           std::sort(stones.begin(), stones.end(), std::less<int>());
           int x = stones.back();
           stones.pop_back();
           int y = stones.back();
           stones.pop_back();
           if (x < y) stones.push_back(y - x);
           else if (x > y) stones.push_back(x - y);
        }
        return stones.size() == 1 ? stones[0] : 0;
    }
};
