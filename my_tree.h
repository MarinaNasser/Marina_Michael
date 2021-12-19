#ifndef MY_TREE_H
#define MY_TREE_H
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
template <class T>
class MyTree{

    private:
    struct Node{
        T data;
        Node* left;
        Node* right;
        //int cnt;
        Node(T value){
            this->data=value;
            this->right=this->left= nullptr;
        }
    };
        Node* root;

        bool searchHelper(Node* temp, T value){
            if(temp== nullptr) return false;
            if(temp->data==value) return true;
            if(value < temp->data)
                searchHelper(temp->left,value);
            else searchHelper(temp->right,value);
        }

        void insertHelper(Node* temp, T value){
            if(value < temp->data){
                if(temp->left== nullptr)
                    temp->left=new Node(value);
                else insertHelper(temp->left,value);
            }
            else{
                if(temp->right== nullptr)
                    temp->right=new Node(value);
                else insertHelper(temp->right,value);
            }
        }

        void inorderHelper(Node* temp){
            if(temp == nullptr) return;
            inorderHelper(temp->left);
            cout<<temp->data<<" ";
            inorderHelper(temp->right);
        }

        void preorderHelper(Node* temp){
            if(temp == nullptr) return;
            cout<<temp->data<<" ";
            preorderHelper(temp->left);
            preorderHelper(temp->right);
        }

        void postorderHelper(Node* temp){
            if(temp == nullptr) return;
            postorderHelper(temp->left);
            postorderHelper(temp->right);
            cout<<temp->data<<" ";
        }

        int sizeofTree(Node* temp){
            if(temp == nullptr)
                return 0;
            else
                return (sizeofTree(temp->left) + 1 + sizeofTree(temp->right));
        }

        Node* minValueNode(Node* node){
            Node* temp = node;
            while (temp && temp->left != nullptr)
                temp = temp->left;
            return temp;
        }

        Node* deleteNodeHelper(Node* root, T key){
            if (root == nullptr) return root;
            if (key < root->data)
                root->left = deleteNodeHelper(root->left, key);
            else if (key > root->data)
                root->right = deleteNodeHelper(root->right, key);
            else{
                if (root->left == nullptr){
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == nullptr){
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNodeHelper(root->right, temp->data);
            }
            return root;
        }

    public:
        MyTree(){
            root = nullptr;
        }
        
        MyTree(vector<T> elements) {
            int x=elements.size()-1;
            sort(elements.begin(),elements.end());
            insertVector(elements,0,x);
            }


        void insertVector(vector<T> &vec,int l,int r)
        {
            if(l > r ) return;
            int mid = (l+r)/2;
            insert(vec[mid]);
            insertVector(vec,l,mid-1);
            insertVector(vec,mid+1,r);
        }

        bool search(T key){
            if(root== nullptr) return false;
            return searchHelper(root, key);
        }
        
        void insert(T key){
            if(root== nullptr){
                root =new Node(key);
            }
            else {
                insertHelper(root,key);
            }
        }
        
        void inorder_rec(){
            if(root!=nullptr)
            {
                inorderHelper(root);
                cout<<endl;
            }
            else return;
        }
        
        void preorder_rec(){
            if(root!=nullptr)
            {
                preorderHelper(root);
                cout<<endl;
            }
            else return;
        }
        
        void postorder_rec(){
            if(root!=nullptr)
            {
                postorderHelper(root);
                cout<<endl;
            }
            else return;
        }
        
        void inorder_it(){
            if (root == nullptr) return;
            stack<Node*> st;
            Node* temp = root;
            while (temp!= nullptr || !st.empty()) {
                while (temp!= nullptr) {
                    st.push(temp);
                    temp = temp->left;
                }
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                temp = temp->right;
            }
            cout<<endl;
        }
        
        void preorder_it(){
            if (root == nullptr) return;
            stack<Node*> st;
            st.push(root);
            Node* temp;
            while (!st.empty())
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                    if(temp->right!= nullptr) st.push(temp->right);
                    if(temp->left!= nullptr)st.push(temp->left);
                }
            cout<<endl;
        }

        void postorder_it(){
            if (root == nullptr) return;
            stack<Node*> st;
            st.push(root);
            stack<int> out;
            while (!st.empty())
            {
                Node* temp = st.top();
                st.pop();
                out.push(temp->data);
                if (temp->left != nullptr) st.push(temp->left);
                if (temp->right != nullptr) st.push(temp->right);
            }
            while (!out.empty())
            {
                cout << out.top() << " ";
                out.pop();
            }
            cout<<endl;
        }

        void breadth_traversal(){
            if(root== nullptr) return;
            queue<Node*> q;
                        q.push(root);
                        while(!q.empty()){
                            Node* temp=q.front();
                            cout<< temp->data <<" ";
                            q.pop();
                            if(temp->left!= nullptr)
                                q.push(temp->left);
                            if(temp->right!= nullptr)
                                q.push(temp->right);
                        }
                        cout<<endl;
        }

        int size(){
            if(root == nullptr) return 0;
            Node* temp = root;
            cout<<sizeofTree(temp)<<" "<<endl;
        }

        void deleteNode(T key){
         root= deleteNodeHelper(root, key);
        }
};

#endif
