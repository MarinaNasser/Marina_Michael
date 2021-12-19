#include "my_tree.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    int tree_size;
    int number_of_operations;
    int element;
    vector<int> v;
    cin >> tree_size >> number_of_operations;
    for (int i = 0; i < tree_size; i++)
    {
        cin >> element;
        v.push_back(element);
    }
    MyTree<int> bst(v);

    while (number_of_operations--)
    {
        int x;
        cin >> x;
        switch (x) {
            case 1:
                cin >> element;
                bst.insert(element);
                break;
            case 2:
                cin>>element;
                cout<<bst.search(element);

                break;
            case 3:
                cin >> element;
                if (element == 1)
                    bst.inorder_rec();
                else if (element == 2)
                    bst.inorder_it();
                break;
            case 4:
                cin >> element;
                if (element == 1)
                    bst.preorder_rec();
                else if (element == 2)
                    bst.preorder_it();
                break;
            case 5:
                cin >> element;
                if (element == 1)
                    bst.postorder_rec();
                else if (element == 2)
                    bst.postorder_it();
                break;
            case 6:
                bst.breadth_traversal();
                break;
            case 7:
                bst.size();
                break;
            case 8:
                cin>>element;
                bst.deleteNode(element);
                bst.inorder_it();
                break;
        }


    }

return 0;
}




