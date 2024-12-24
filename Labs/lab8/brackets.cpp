#include <iostream>

bool brackets(const char* a) {
    char s[ 100001]; 
    int top = -1;

    for (int i = 0; a[i] != '\0'; ++i) {
        char ch = a[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            s[++top] = ch;
            continue;
        }

        if (top == -1)
            return false;

        char x = s[top--];

        switch (ch) {
            case ')':
                if (x == '{' || x == '[')
                    return false;
                break;

            case ']':
                if (x == '(' || x == '{')
                    return false;
                break;

            case '}':
                if (x == '(' || x == '[')
                    return false;
                break;
        }
    }

    return top == -1;
}

int main() {
    char a[100001];
    std::cin >> a;

    if (brackets(a))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}
