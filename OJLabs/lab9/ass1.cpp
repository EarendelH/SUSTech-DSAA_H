#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Node {
public:
    char value;
    Node* left;
    Node* right;
    Node(char val) : value(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(const string& expression) {
    stack<Node*> st;
    for (int i = expression.length() - 1; i >= 0; --i) {
        char ch = expression[i];
        if (ch == ' ' || ch == ',' || ch == '(' || ch == ')') continue;
        Node* node = new Node(ch);
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            node->left = st.top(); st.pop();
            node->right = st.top(); st.pop();
        }
        st.push(node);
    }
    return st.top();
}

void inorder(Node* root) {
    if (root == nullptr) return;
    if (root->left || root->right) cout << "(";
    inorder(root->left);
    cout << root->value;
    inorder(root->right);
    if (root->left || root->right) cout << ")";
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->value;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value;
}

int main() {
    string expression;
    cin >> expression;
    Node* root = buildTree(expression);
    
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    
}