class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int w1, w2;
        w1 = w2 = 0;

        while (result.size() < word1.size() + word2.size()) {
            if (w1 >= word1.size()) {
                result.push_back(word2[w2++]);
                continue;
            }
            else if (w2 >= word2.size()) {
                result.push_back(word1[w1++]);
                continue;
            }
            else {
                result.push_back(word1[w1++]);
                result.push_back(word2[w2++]);
            }
        }
        return result;
    }
};