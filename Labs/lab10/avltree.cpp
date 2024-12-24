#include <iostream>
using namespace std;

class Node
{
    public:
        int value;
        int h;
        Node* left;
        Node* right;
        Node(int k) {
            this->value=k;
            this->left=nullptr;
            this->right=nullptr;
            this->h=1;
        }
};

int maxx(int a, int b) {
    if(a>b) return a;
    return b;
}
int get_height(Node* n) {
    if(n==nullptr) return 0;
    return n->h;
}

int balence_number(Node* n) {
    if(n==nullptr)return 0;
    return get_height(n->left)-get_height(n->right);

}

Node* right_rotate(Node* y)
{

    Node* x=y->left;
    Node* tmp=x->right;
    x->right= y;
    y->left =tmp;
    y->h= maxx(get_height(y->left),get_height(y->right))+1;
    x->h= maxx(get_height(x->left), get_height(x->right))+1;
    return x;

}
Node* left_rotate(Node* x) 
{
    Node* y= x->right;
    Node* tmp= y->left;
    y->left= x;
    x->right= tmp;
    x->h= maxx(get_height(x->left),get_height(x->right))+1;
    y->h=maxx(get_height(y->left),get_height(y->right))+1;
    return y;

}

Node* insert(Node* node, int value) {

    if (node==nullptr)
    {
        return new Node(value);
    }
    if (value<node->value) {
        node->left=insert(node->left,value);
    }
    else if (value>node->value) {
        if(value==node->value) return node;
        node->right= insert(node->right,value);
    }
    

    node->h=maxx(get_height(node->left),get_height(node->right))+1;


    int b=balence_number(node);
    if (b>1&&value<(node->left->value)) {
        return right_rotate(node);
    }
    else if (b<-1&&value>(node->right->value))
    {
        return left_rotate(node);
    }
    else if (b>1&&value>node->left->value) {
        node->left=left_rotate(node->left);
        return right_rotate(node);
    }
    else if (b<-1&&value< node->right->value) {
        node->right=right_rotate(node->right);
        return left_rotate(node);
    }


    return node;
}

Node* find_min(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* delete1(Node* root, int key) {
    if (root==nullptr) return root;

    if (key<root->value)
        root->left=delete1(root->left,key);
    else if (key > root->value)
        root->right=delete1(root->right,key);
    else {
        if ((root->left==nullptr)||(root->right==nullptr)){

            Node* temp;
            if(root->left==nullptr) {
                temp= root->right;
            }
            else {
                temp= root->left;
            }
            
            if (temp==nullptr) 
            {
                temp= root;
                root= nullptr;
            } 
            else{
                *root= *temp;
            }

            delete temp;
        } 
        else {
            Node* temp = find_min(root->right);
            root->value = temp->value;
            root->right = delete1(root->right, temp->value);
        }
    }

    if (root==nullptr) return root;

    root->h= maxx(get_height(root->left), get_height(root->right))+1;

    int b= balence_number(root);
    if(b>1&&balence_number(root->left)>=0) {
        return right_rotate(root);
    }
    if(b>1&& balence_number(root->left)<0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(b<-1&& balence_number(root->right)<=0){
        return left_rotate(root);
    }
    if (b< -1&& balence_number(root->right)>0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}

void preorder(Node* root) {
    if (root) 
    {
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main() {
    int n,m,a[100002],b[100002];
    Node* root=nullptr;

    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    cin>>m;
    for (int i=0;i<m;i++) {
        cin>>b[i];
    }

    for (int i=0;i<n;i++) {
        root=insert(root,a[i]);
    }
    if(n!=0){
        preorder(root);
    }
    
    cout<<endl;


    for (int i=0;i<m;i++) {
        root=delete1(root,b[i]);
    }
    if(m!=0){
        preorder(root);
    }
    
    

}



