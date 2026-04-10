class Solution {
public:
    int mostFrequent(unordered_map<char, int>& counter) {
        return max_element(counter.begin(), counter.end(), 
        [](pair<char, int> elem1, pair<char, int> elem2){
            return elem1.second < elem2.second;
        })->second;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> counter;
        int max_len = 0;
        int l = 0, r = 0;

        while (r < s.size()) {
            auto substr_size = r - l + 1;
            counter[s[r]]++;
            if (counter.empty() || substr_size - mostFrequent(counter) <= k) {
                max_len = max(max_len, substr_size);
            }
            else counter[s[l++]]--;
            r++;
        }
        
        return max_len;
    }
};
