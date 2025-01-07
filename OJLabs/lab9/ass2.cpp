#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    long long key;
    long long value;
    Node* left;
    Node* right;
    Node(long long k, long long v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, long long key, long long value) {
    if (root == nullptr) return new Node(key, value);
    if (key < root->key) root->left = insert(root->left, key, value);
    else if (key > root->key) root->right = insert(root->right, key, value);
    return root;
}

Node* find(Node* root, long long key) {
    if (root == nullptr || root->key == key) return root;
    if (key < root->key) return find(root->left, key);
    return find(root->right, key);
}

void modify(Node* root, long long key, long long new_value) {
    Node* node = find(root, key);
    if (node != nullptr) node->value = new_value;
}

long long sumOfValue(Node* root) {
    if (root == nullptr) return 0;
    return root->value + sumOfValue(root->left) + sumOfValue(root->right);
}

int main() {
    int k;
    cin >> k;
    Node* root = nullptr;
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        if (s == "insert") {
            long long key, value;
            cin >> key >> value;
            root = insert(root, key, value);
        } else if (s == "modify") {
            long long key, new_value;
            cin >> key >> new_value;
            modify(root, key, new_value);
        } else if (s == "sum") {
            long long key;
            cin >> key;
            Node* node = find(root, key);
            if (node != nullptr) cout << sumOfValue(node) << endl;
        }
    }
}