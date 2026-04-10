// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> result;

        for (int i = 0; i < pairs.size(); ++i) {
            
            int j = i;
            Pair curr = pairs[i];

            while (j > 0 && curr.key < pairs[j - 1].key) {
                pairs[j] = pairs[j - 1];
                j--;
            }
            pairs[j] = curr;
            result.push_back(pairs);
        }

        return result;
    }
};
