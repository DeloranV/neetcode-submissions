class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> operators = {"+", "-", "*", "/"};
        stack<int> num_stack;

        for (auto& token : tokens) {
            if (operators.find(token) == operators.end()) num_stack.push(stoi(token));
            else {
                auto num2 = num_stack.top();
                num_stack.pop();
                auto num1 = num_stack.top();
                num_stack.pop();
                if (token == "+") num_stack.push(num1 + num2);
                else if (token == "-") num_stack.push(num1 - num2);
                else if (token == "*") num_stack.push(num1 * num2);
                else num_stack.push(num1 / num2);
            }
        }
        return num_stack.top();
    }
};
