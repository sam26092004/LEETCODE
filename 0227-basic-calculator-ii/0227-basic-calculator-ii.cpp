class Solution {
public:
    int precedence(char operation) {
        return (operation == '+' || operation == '-') ? 1 : 2;
    }

    int applyOperation(int a, int b, char operation) {
        switch (operation) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    }

    int calculate(string s) {
        stack<int> operands;
        stack<char> operators;
        int num = 0;
        bool hasNum = false;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
                hasNum = true;
            } 
            else if (ch == ' ') continue;

            else { 
                if (hasNum) {
                    operands.push(num);
                    num = 0;
                    hasNum = false;
                }

                while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                    int b = operands.top(); operands.pop();
                    int a = operands.top(); operands.pop();
                    char op = operators.top(); operators.pop();
                    operands.push(applyOperation(a, b, op));
                }
                operators.push(ch);
            }
        }

        if (hasNum) operands.push(num);

        while (!operators.empty()) {
            int b = operands.top(); operands.pop();
            int a = operands.top(); operands.pop();
            char op = operators.top(); operators.pop();
            operands.push(applyOperation(a, b, op));
        }

        return operands.top();
    }
};
