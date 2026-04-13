class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        auto cmp = [](auto& p1, auto& p2){ return p1.first < p2.first; };
        int time = 0;
        queue<pair<int, int>> cooldown_q;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> max_hp {cmp};
        unordered_map<char, int> freq;

        for (auto& t : tasks) freq[t]++;
        for (auto& c : freq) max_hp.push({c.second, 0});

        while (!cooldown_q.empty() || !max_hp.empty()) {
            time++;
            if (!cooldown_q.empty()) {
                auto frontElem = cooldown_q.front();
                if (frontElem.second == time) {
                    max_hp.push(frontElem);
                    cooldown_q.pop();
                } 
            }
            if (!max_hp.empty()) {
                auto curr_task = max_hp.top();
                max_hp.pop();
                curr_task.first--;
                curr_task.second = time + n + 1;
                if (curr_task.first > 0) cooldown_q.push(curr_task);
            }
             
        }
        return time;
    }
};
