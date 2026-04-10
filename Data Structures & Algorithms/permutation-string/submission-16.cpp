class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_counter;
        unordered_map<char, int> window_counter;
        int l = 0, r = 0;

        while(r < s1.size()) {
            s1_counter[s1[r]]++;
            window_counter[s2[r++]]++;
        }
        if (s1_counter == window_counter) return true;
        
        while(r < s2.size()) {
            window_counter[s2[r++]]++;
            if (--window_counter[s2[l]] <= 0) window_counter.erase(s2[l]);
            l++;
            if (s1_counter == window_counter) return true;
        }

        return false;   
    }
};
