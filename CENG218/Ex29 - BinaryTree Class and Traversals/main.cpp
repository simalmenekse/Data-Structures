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
};

int main(){

    TreeNode<int> *LChild3 = new TreeNode<int>(4);
    TreeNode<int> *LChild2 = new TreeNode<int>(3, LChild3);
    TreeNode<int> *LChild1 = new TreeNode<int>(2,LChild2);

    TreeNode<int> T1(1, LChild1);

    cout << "Tree root value: " << T1.getData() << endl;
    cout << "LChild1 value: " << LChild1->getData() << endl;
    cout << "LChild2 value: " << LChild2->getData() << endl;
    cout << "LChild3 value: " << LChild3->getData() << endl;

    cout << "Preorder traversal: ";
    TreeNode<int>::Preorder(&T1);

    cout << "Postorder traversal: ";
    TreeNode<int>::PostOrder(&T1);

        cout << "Inoder traversal: ";
    TreeNode<int>::InOrder(&T1);


}