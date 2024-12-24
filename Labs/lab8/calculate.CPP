#include <iostream>
#include <stack>

int calc(int n) {
    std::stack<int> stack;
    std::string token;

    for (int i = 0; i < n; ++i) {
        std::cin >> token;
        if (token == "+" || token == "-" || token == "*") {
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();
            if (token == "+") {
                stack.push(operand1 + operand2);
            } else if (token == "-") {
                stack.push(operand1 - operand2);
            } else if (token == "*") {
                stack.push(operand1 * operand2);
            }
        } else {
            stack.push(std::stoi(token));
        }
    }

    return stack.top();
}

int main() {
    int n;
    std::cin >> n;

    int result = calc(n);
    std::cout << result << std::endl;

    return 0;
}
