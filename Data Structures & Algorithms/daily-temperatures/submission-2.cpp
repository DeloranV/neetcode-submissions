class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> smaller_indexes;
        vector<int> result(temperatures.size(), 0);

        for (int i {0}; i < temperatures.size(); ++i) {
            if (smaller_indexes.size() == 0 || temperatures[i] <= temperatures[smaller_indexes.top()]) smaller_indexes.push(i);
            else {
                while(smaller_indexes.size() != 0 && temperatures[i] > temperatures[smaller_indexes.top()]) {
                    result[smaller_indexes.top()] = i - smaller_indexes.top();
                    smaller_indexes.pop();
                    
                }
                smaller_indexes.push(i);
            }
        }
        return result;
    }
};
