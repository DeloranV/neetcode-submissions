class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minRate, maxRate, result;
        minRate = 1;
        maxRate = *std::max_element(piles.begin(), piles.end());
        result = std::numeric_limits<int>::max();

        while (minRate <= maxRate) {
            int midRate = minRate + ((maxRate - minRate + 1) / 2);
            int nHours = 0;
            for (auto& pile : piles) nHours += ((pile + midRate - 1) / midRate);
            if (nHours > h) minRate = midRate + 1;
            else if (nHours <= h) {
                result = std::min(result, midRate);
                maxRate = midRate - 1;
            } 
        }
        return result;
    }
};
