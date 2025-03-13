class Solution {
public:
  int calculate(string op, int a, int b) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "/") return a / b;
        return a * b;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(calculate(token, a, b));
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};