#include <iostream>
using namespace std;

template <class T>
class TreeNode {

    private:
        T data;
    public:
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(){left=right=NULL; }
        TreeNode(T D, TreeNode<T> *L=0, TreeNode<T> *R=0){
                left = L;
                right = R;
                data = D;
        }

        T getData(){return data; }
        void setData(T D){data = D; }

        static void Preorder(TreeNode<T> *node){
            if(node != NULL){
                cout << node ->data << " ";
                Preorder(node->left);
                Preorder(node->right);
            }
        }
        static void PostOrder(TreeNode<T>*node){
            if(node!=NULL){
                PostOrder(node->left);
                PostOrder(node->right);
                cout << node->data << " ";
            }
        }
        
        static void InOrder(TreeNode <T> *node){
            if(node != NULL){
                InOrder(node->left);
                cout << node->data << " ";
                InOrder(node->right);
            }
        }

        int countNodes(){
            int lcnt=0, rcnt=0;
            if(left!=NULL) lcnt = left->countNodes();
            if(right!=NULL) rcnt = right->countNodes();
            return 1 + lcnt + rcnt;
        }
};

int main(){

    TreeNode<int> *LChild3 = new TreeNode<int>(4);
    TreeNode<int> *LChild2 = new TreeNode<int>(3, LChild3);
    TreeNode<int> *LChild1 = new TreeNode<int>(2,LChild2);

    TreeNode<int> *RChild2 = new TreeNode<int>(11);
    TreeNode<int> *RChild1 = new TreeNode<int>(10,0,RChild2);

    TreeNode<int> T1(1, LChild1, RChild1);

    cout << "Count Nodes: " << T1.countNodes() << endl;


    cout << "Preorder traversal: ";
    TreeNode<int>::Preorder(&T1);

    cout << "Postorder traversal: ";
    TreeNode<int>::PostOrder(&T1);

        cout << "Inoder traversal: ";
    TreeNode<int>::InOrder(&T1);


}