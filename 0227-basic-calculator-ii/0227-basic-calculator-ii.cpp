class Solution {
public:
    int precedence(char operation) {
        return (operation == '+' || operation == '-') ?  1 : 2;
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
        stack<int> operand;
        stack<char> opstack;
        int num = 0;
        bool hasNum = false;

        for (int i = 0; i < s.size(); i++) {
            if (isspace(s[i]))
                continue;
            else if (isdigit(s[i])) {
                hasNum = true;
                num = num * 10 + (s[i] - '0');
            } else {
               if (hasNum) {
                    operand.push(num);
                    num = 0;
                    hasNum = false;
                }
                while (!opstack.empty() &&
                       precedence(opstack.top()) >= precedence(s[i])) {
                    int num1 = operand.top();
                    operand.pop();
                    int num2 = operand.top();
                    operand.pop();
                    char operation = opstack.top();
                    opstack.pop();
                    int result = applyOperation(num2, num1, operation);
                    operand.push(result);
                }
                opstack.push(s[i]);
            }
        }
        if (hasNum) {
            operand.push(num);
        }
        while (!opstack.empty()) {
            int b = operand.top(); operand.pop();
            int a = operand.top(); operand.pop();
            char op = opstack.top(); opstack.pop();
            operand.push(applyOperation(a, b, op));
        }
        return operand.top();
    }
};