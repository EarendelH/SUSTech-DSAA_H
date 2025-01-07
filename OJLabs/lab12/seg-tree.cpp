#include <iostream>

using namespace std;
struct Node {
    Node* leftSon;
    Node* rightSon;
    int leftEndPoint;
    int rightEndPoint;
    int sum;

    Node(int l,int r):leftSon(nullptr),rightSon(nullptr),leftEndPoint(l),rightEndPoint(r),sum(0){}
};

class Segtree
{
public:
    Segtree(int n){
        root=build(0, n-1);
    }

    void update(int index, int value){
        update(root,index,value);
    }

    int query(int left, int right){
        return do_sum(root,left,right);
    }

private:
    Node* root;
    Node* build(int l,int r){
        Node* node=new Node(l, r);
        if(l==r)
        {
            return node;
        }
        int mid=(l+r)/2;
        node->leftSon=build(l,mid);
        node->rightSon =build(mid+1,r);
        return node;
    }

    void update(Node* node,int index,int value) {
        if (node->leftEndPoint==node->rightEndPoint) {
            node->sum=value;
            return;
        }
        int mid = ((node->leftEndPoint)+(node->rightEndPoint))/2;
        if (index<=mid) {
            update(node->leftSon,index,value);
        } else {
            update(node->rightSon,index,value);
        }
        node->sum=(node->leftSon->sum)+(node->rightSon->sum);
    }

    int do_sum(Node* node, int left, int right) {
        if (node->leftEndPoint==left&&node->rightEndPoint==right)
        {
            return node->sum;
        }
        int mid=(node->leftEndPoint+node->rightEndPoint)/2;
        if (right<=mid) 
        {
            return do_sum(node->leftSon,left,right);
        } else if (left>mid)
        {
            return do_sum(node->rightSon,left,right);
        } else 
        {
            return do_sum(node->leftSon,left,mid)+do_sum(node->rightSon,mid+1,right);
        }
    }
};

int main() {
    int n,q;
    cin>>n>>q;

    Segtree segTree(n);
    int type,a,b;
    for(int i=0;i<q;i++)
    {
        cin>>type>>a>>b;
        if(type==1)
        {
            segTree.update(a-1,b);
        }
        else if(type==2)
        {
            cout<<segTree.query(a-1,b-1)<<endl;
        }
    }

}