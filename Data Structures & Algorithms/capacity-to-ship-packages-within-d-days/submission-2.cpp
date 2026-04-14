class Solution {
public:
    int daysToShip(vector<int>& weights, int weight_cap) {
        int days = 1;
        int remaining_cap = weight_cap;

        for (auto& w : weights) {
            if (w > remaining_cap) {
                days++; remaining_cap = weight_cap;
            }
            remaining_cap -= w;
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int total_weight = 0;
        for (auto& w : weights) total_weight += w;

        int l = *max_element(weights.begin(), weights.end());
        int r = total_weight;

        int min_capacity = numeric_limits<int>::max();
        while (l <= r) {
            int mid = (l + r) / 2;
            
            int l_days = daysToShip(weights, l);
            int r_days = daysToShip(weights, r);
            int mid_days = daysToShip(weights, mid);

            if (l_days <= days) min_capacity = min(min_capacity, l);
            if (r_days <= days) min_capacity = min(min_capacity, r);
            if (mid_days <= days) min_capacity = min(min_capacity, mid);

            if (mid_days <= days) {
                if (mid_days == days) min_capacity = min(min_capacity, mid);
                r = mid - 1;
            } 
            else if (mid_days > days) l = mid + 1;
        }

        return min_capacity;
    }
};