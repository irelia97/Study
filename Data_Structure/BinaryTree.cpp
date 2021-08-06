#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

typedef struct node{
    node* left;
    node* right;
    int data;
    node(int x = 0):data(x), left(nullptr), right(nullptr){}
}treeNode;

class BinaryTree{
private:
    treeNode* root;
public:
    BinaryTree() : root(nullptr){}
    BinaryTree(const vector<int>& data) : root(nullptr){
        for(auto x : data)
            insert(x, root);
    }

    //  由前序序列、中序序列构建唯一二叉树
    void createBitree(treeNode*& t, vector<int> preV, vector<int> inV){
        if( preV.size() == 0 ){
            t = nullptr;
            return;
        }

        int index = 0;
        for(int i = 0; i < inV.size(); ++i){
            if( preV[0] == inV[i] ){
                index = i;
                break;
            }
        }

        // t = new treeNode(preV[0]);
        // createBitree(t->left, vector<int>(preV.begin()+1, preV.begin() + index),
        //     vector<int>())
    }

    void preOrder(treeNode* p){
        if( p != nullptr ){
            cout << p->data << " ";
            preOrder(p->left);
            preOrder(p->right);
        }
    }
    void noR_preOrder(treeNode* p){
        stack<treeNode*> stk;
        while( !stk.empty() || p != nullptr ){
            while( p != nullptr ){
                cout << p->data << " ";
                stk.push(p);
                p = p->left;
            }
            if( !stk.empty() ){
                p = stk.top()->right;
                stk.pop();
            }
        }
    }

    void inOrder(treeNode* p){
        if( p != nullptr ){
            inOrder(p->left);
            cout << p->data << " ";
            inOrder(p->right);
        }
    }
    void noR_inOrder(treeNode* p){
        stack<treeNode*> stk;
        while( !stk.empty() || p != nullptr ){
            while( p != nullptr ){
                stk.push(p);
                p = p->left;
            }
            if( !stk.empty() ){
                p = stk.top();
                cout << p->data << " ";
                p = p->right;
                stk.pop();
            }
        }
    }    

    void postOrder(treeNode* p){
        if( p != nullptr ){
            postOrder(p->left);
            postOrder(p->right);
            cout << p->data << " ";
        }
    }
    void noR_postOrder(treeNode* p){
        if( p == nullptr )
            return;

        treeNode* pre = nullptr;
        stack<treeNode*> stk;
        stk.push(p);
        while( !stk.empty() ){
            p = stk.top();
            if( (!p->left && !p->right) || 
                (pre&&(p->left==pre || p->right==pre)) ){
                cout << p->data << " ";
                stk.pop();
                pre = p;
            }else{
                if( p->right ) stk.push(p->right);
                if( p->left  ) stk.push(p->left);
            }
        }
    }

    void insert(int x, treeNode*& p){
        if( p == nullptr ){
            p = new treeNode(x);
        }else{
            if( x < p->data ) insert(x, p->left);
            else if( x > p->data ) insert(x, p->right);
            else return;
        }
    }

    void remove(int x, treeNode*& p){
        while( p != nullptr ){
            if( x < p->data ) remove(x, p->left);
            else if( x > root->data ) remove(x, p->right);
            else if( p->left && p->right ){
                //  p->data == x, 且左右结点均不为空
                //  可在左子树的儿子中找最大结点(一直right)替代，再递归删除该最大结点
                //  可在右子树的儿子中找最小结点(一直left)替代，再递归删除该最小结点
                treeNode* rightMaxNode = p->right;
                while( rightMaxNode->left != nullptr )
                    rightMaxNode = rightMaxNode->left;
                p->data = rightMaxNode->data;
                remove(rightMaxNode->data, p->right);
            }else{
                treeNode* tmp = p;
                if( p->left == nullptr ) p = p->right;
                else if( p->right == nullptr ) p = p->left;
                delete tmp; 
            }
        }
    }

    treeNode* getRoot() { return root; }
};

int main()
{
    vector<int> vec{53, 17, 78, 9, 45, 65, 87, 23};
    BinaryTree bt(vec);

    bt.preOrder(bt.getRoot());
    cout << "\n";
    bt.noR_preOrder(bt.getRoot());
    cout << "\n";
    bt.inOrder(bt.getRoot());
    cout << "\n";
    bt.noR_inOrder(bt.getRoot());
    cout << "\n";

    bt.postOrder(bt.getRoot());
    cout << "\n";
    bt.noR_postOrder(bt.getRoot());
    cout << "\n";

    return 0;
}