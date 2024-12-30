#include <iostream>
using namespace std;
struct treenode
{
    int data;
    treenode* left;
    treenode* right;
    treenode(int d)
    {
        data = d;
        left=right=nullptr;
    }
};
class Tree
{
    treenode* root;
    public:
    Tree();
    ~Tree();
    treenode* insert_node(treenode* r,int d);
    void deletetree(treenode* Node);
    void inorder(treenode* r);
    void preorder(treenode* r);
    void postorder(treenode* r);
    void insert(int k);
    treenode* getroot()
    {
        return root;
    }
    bool is_empty();
    treenode* search(treenode* r,int k);
    treenode* find_min(treenode* r);
    treenode* find_max(treenode* r);
    treenode* del_min(treenode* r);
    treenode* del_max(treenode* r);
    treenode* del_node(treenode* r, int k);
    void delete_key(int k);
    void simplify_search(int k);
};
bool Tree::is_empty()
{
    return root == nullptr;
}
Tree::Tree()
{
    root=nullptr;
}
void Tree::deletetree(treenode* Node)
{
    if(Node==nullptr)
    {
        return;
    }
    deletetree(Node->left);
    deletetree(Node->right);
    delete Node;
}
Tree::~Tree()
{
    deletetree(root);
    root=nullptr;
}
treenode* Tree::insert_node(treenode* r,int d)
{
    if(r==nullptr)
    {
        return new treenode(d);
    }
    if(r->data==d)
    {
        return r;
    }
    if(r->data > d)
    {
        r->left=insert_node(r->left,d);
    }
    else
    {
        r->right=insert_node(r->right,d);
    }
    return r;
}
void Tree::insert(int k)
{
    root=insert_node(root,k);
}
void Tree::inorder(treenode* r)
{
    if(r!=nullptr)
    {
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
}
void Tree::preorder(treenode* r)
{
    if(r!=nullptr)
    {
        cout<<r->data<<" ";
        preorder(r->left);
        preorder(r->right);
    }
}
void Tree::postorder(treenode* r)
{
    if(r!=nullptr)
    {
        postorder(r->left);
        postorder(r->right);
        cout<<r->data<<" ";
    }
}
treenode* Tree::search(treenode* r,int k)
{
    if(r==nullptr || r->data==k)
    {
        return r;
    }
    if(r->data > k)
    {
        return search(r->left,k);
    }

    return search(r->right,k);
}
treenode* Tree::find_min(treenode* r)
{
    if(r==nullptr)
    {
        return nullptr;
    }
    treenode* cur=r;
    while (cur->left!=nullptr)
    {
        cur=cur->left;
    }
    return cur;
}
treenode* Tree::find_max(treenode* r)
{
    if(r==nullptr)
    {
        return nullptr;
    }
    treenode* cur=r;
    while (cur->right!=nullptr)
    {
        cur=cur->right;
    }
    return cur;
}
treenode* Tree::del_min(treenode* r)
{
    if (r == nullptr) {
        return nullptr; // Tree is empty
    }
    treenode* cur=r;
    treenode* parent=nullptr;
    while (cur->left!=nullptr)
    {
        parent=cur;
        cur=cur->left;
    }
    if(parent)
    {
        parent->left=cur->right;
    }
    else
    {
        r=cur->right;
    }
    delete cur;
    return r;
}
treenode* Tree::del_max(treenode* r)
{
    if(r==nullptr)
    {
        return nullptr;
    }
    treenode* parent=nullptr;
    treenode* cur=r;
    while (cur->right)
    {
        parent=cur;
        cur=cur->right;
    }
    if(parent)
    {
        parent->right=cur->left;
    }
    else
    {
        r=cur->left;
    }
    delete cur;
    return r;
}
treenode* Tree::del_node(treenode* r,int k)
{
    if (r==nullptr)
    {
        return  nullptr;    //base case
    }
    if(k<r->data)
    r->left=del_node(r->left,k);
    if(k>r->data)
    r->right=del_node(r->right,k);
    else
    {
        //now we find the node to be deleted.
        // there are three cases 
        // 1. node has no children or node has one child of right.
        if(r->left==nullptr)
        {
            treenode* temp=r->right;
            delete r;
            return temp;
        }
        else if(r->right==nullptr) //2. node has one child of left.
        {
            treenode* temp=r->left;
            delete r;
            return temp;
        }
        //3.node has two children.
        treenode* successor;
        successor= find_min(r->right);
        r->data=successor->data;
        r->right=del_node(r->right,successor->data);
    }
    return r;
}
void Tree::delete_key(int k)
{
    root=del_node(root,k);
}
void Tree::simplify_search(int k)
{
    if(search(root,k))
    {
        cout<<"Key "<<k<<" is present in the tree"<<endl;
    }
    else
    {
        cout<<"Key "<<k<<" is not present in the tree"<<endl;
    }
}
int main()
{
    cout<<"\n+++++Guide+++++";
    cout<<"\n 1.Insert\n2.Delete\n3.Print inorder\n4.Print postorder\n5.Print preorder";
    cout<<"\n6.Check if tree is empty\n7.Search\n8.Find Min\n9.Find Max\n10.Delete Min\n11.Delete max \n12.Exit\n";
    Tree t;
    bool co=true;
    while (co)
    {
        int ch;
        cout<<"\nPlease enter your choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter the value to be inserted: ";
            int val;
            cin>>val;
            t.insert(val);
            break;
        case 2:
            cout<<"Enter the value to be deleted: ";
            int del;
            cin>>del;
            t.delete_key(del);
            break;
        case 3:
            if (!t.is_empty()) {
            t.inorder(t.getroot());
            } else {
            cout << "Tree is empty.";
            }
            break;
        case 4:
            if (!t.is_empty()) {
            t.postorder(t.getroot());
            } else {
            cout << "Tree is empty.";
            }
            break;
        case 5:
            if (!t.is_empty()) {
            t.preorder(t.getroot());
            } else {
            cout << "Tree is empty.";
            }
            break;
        case 6:
            if (t.is_empty())
            cout<<"Tree is empty";
            else
            cout<<"Tree is not empty";
            break;
        case 7:
            cout<<"Enter the value to be searched: ";
            int s;
            cin>>s;
            t.simplify_search(s);
            break;
        case 8:
        cout<<"Min value is: "<<t.find_min(t.getroot())->data;
        break;
        case 9:
        cout<<"Max value is: "<<t.find_max(t.getroot())->data;
        break;
        case 10:
        t.delete_key(t.find_min(t.getroot())->data);
        cout<<"Min value was deleted";
        break;
        case 11:
        t.delete_key(t.find_max(t.getroot())->data);
        cout<<"Max value was deleted";
        break;
        case 12:
        co=false;
        cout << "Exiting...";
        break;
        default:
        cout<<"Invalid choice";
            break;
        }
    }
    
}