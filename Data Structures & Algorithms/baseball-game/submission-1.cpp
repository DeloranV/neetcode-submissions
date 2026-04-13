class Solution {
public:
    int calPoints(vector<string>& operations) {
        int result = 0;
        vector<int> s_operations;

        for (auto& o : operations) {
            if (o == "+") {
                int lhs = s_operations.back(); s_operations.pop_back();
                int rhs = s_operations.back(); s_operations.pop_back();
                int result = lhs + rhs;
                s_operations.push_back(rhs); s_operations.push_back(lhs); s_operations.push_back(result);
            }
            else if (o == "D") {
                int result = s_operations.back() * 2;
                s_operations.push_back(result);
            }
            else if (o == "C") s_operations.pop_back();
            else s_operations.push_back(stoi(o));
        }
        for (auto& n : s_operations) result += n;
        return result;
    }
};