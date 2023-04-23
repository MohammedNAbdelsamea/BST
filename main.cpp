#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
class BST{
public:
Node*root;
public:
BST(){
    root= nullptr;
}
    Node* insert(Node* root, int item) {
        if(root == NULL)
        {
//            return new Node(data);
            Node*newnode=new Node(item);
            root=newnode;
        } else if(item<=root->data){
            root->left= insert(root->left,item);
        }
        else if (item>root->data){
            root->right= insert(root->right,item);
        }
        return root;

      }
      void Insert(int item)
      {
    root= insert(root,item);
       }
       void Preorder(Node*root)
{
    if(root== nullptr)return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

    void Inorder(Node*root)
    {
        if(root== nullptr)return;
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }

    void Postorder(Node*root)
    {
        if(root== nullptr)return;
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<" ";
    }

Node*search(Node*r,int key)
{
    if(r== nullptr) {return nullptr;}
    else if(r->data==key)return r;
    else if(r->data<key)return search(r->left,key);
    else return search(r->right,key);

}
bool Search(int key){
    Node*result= search(root,key);
    if(result== nullptr)return false;
    else return true;
}
Node *Findmax(Node*r){
    if(r== nullptr)return nullptr;
    else if(r->right== nullptr)return r;
    else return Findmax(r->right);
}
    Node *Findmin(Node*r){
        if(r== nullptr)return nullptr;
        else if(r->left== nullptr)return r;
        else return Findmin(r->left);
    }
    Node*Delete(Node*r,int key)
    {
    if(r== nullptr)return nullptr;
    if(key<r->data)r->left= Delete(r->left,key);
    else if(key>r->data)r->right= Delete(r->right,key);
    else
    {
    if(r->left== nullptr&&r->right== nullptr)r= nullptr;
    else if(r->left!= nullptr&&r->right== nullptr)
    {
        r->data=r->left->data;
        delete r->left;
        r->left= nullptr;
    }
    else if(r->left== nullptr&&r->right!= nullptr)
    {
        r->data=r->right->data;
        delete r->right;
        r->left= nullptr;
    } else
    {
        Node*prev= Findmax(r->left);
        r->data=prev->data;
        r->left= Delete(r->left,prev->data);
    }
    }return r;


}
};


int main() {
BST b ;
    b.Insert(45);
    b.Insert(15);
    b.Insert(79);
    b.Insert(90);
    b.Insert(10);
    b.Insert(55);
    b.Insert(12);
    b.Insert(20);
    b.Insert(50);
    cout<<"The content: "<<endl;
    b.Preorder(b.root);
//    cout<<"\n";
//
//    b.Inorder(b.root);
//    cout<<"\n";
//    b.Postorder(b.root);
//    cout<<"\n";

//    int key;
//    cout<<"Enter num";
//    cin>>key;
//    if (b.Search(key)) cout<<"OK";
//    else cout<<"NO";
//cout<<"Minnn"<<endl;
//Node *min=b.Findmin(b.root);
//if(min==0)//NULL
//cout<<"empty";
//else cout<<"Min:"<<min->data<<endl;
//    cout<<"Maxxx"<<endl;
//    Node *max=b.Findmax(b.root);
//    if(max==0)//NULL
//        cout<<"empty";
//    else cout<<"Max:"<<max->data;
cout<<"Delettee";
Node*res=b.Delete(b.root,12);
cout<<"after 12:"<<endl;
b.Preorder(res);
    res=b.Delete(b.root,15);
    cout<<"after 15:"<<endl;
    b.Preorder(res);

}
