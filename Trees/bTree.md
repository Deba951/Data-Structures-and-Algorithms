# Traversing a tree

## `DFS`

### Preorder Traversal
`Root Left Right`

```cpp
void(preorder){
    if(node==null)
        return;

    print(node.data);
    preorder(node.left);
    preorder(node.right);
}
```

- Time complexity: O(n) where n is the number of nodes in the tree.
- Space complexity: O(h) where h is the height of the tree


### Inorder Traversal
`Left Root Right`

```cpp
void (inorder){
    if(node==null)
        return;

    print(node.left);
    print(node.data);
    print(node.right);
}
```

### Postorder Traversal
`Left Right Root`

```cpp
void (postorder){
    if(node==null)
        return;

    print(node.left);
    print(node.right);
    print(node.data);
}
```

---

## `Level Order Traversal (BFS)`
Queue is used to store the nodes during traversal
- Time complexity: O(n) where n is the number of nodes in the tree.
- Space Complexity: O(n)

```cpp
class Sol{
    public:
        vector<vector<int>> levelOrder(TreeNode* root){
            vector<vector<int>> finalTree;

            // If the root is null, return the empty vector
            if(root == NULL)
                return finalTree;

            // Initialising the queue to store the Nodes
            queue<TreeNode*> q;
            // Pushing the root node
            q.push(root);

            while(!q.empty()){
                
                int size=q.size();
                // Vector to store the nodes at a level-wise order
                vector<int> level;

                // Iterating through the queue
                for(int i=0; i<size; i++){
                    TreeNode *node = q.front();
                    q.pop();

                    if(node->left != NULL)
                        q.push(node->left);

                    if(node->right != NULL)
                        q.push(node->right);

                    level.push_back(node->val);
                }

                finalTree.push_back(level);
            }

            return finalTree;
        }
};

```

---

## `Complete Binary Tree`

```cpp
#include <bits/stdc++.h>
using namespace std;

// Creating the Node
class node{
    public:
        int data;
        node* left;
        node* right;

    // Constructor
    node(int value){
        this -> data = value;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// Building the Tree. Recursive Function.
node* buildTree (node* root){
    cout << "Enter the data: " << endl;
    
    int data;
    cin >> data;    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // Calling the constructor and creating the root node
    root = new node(data);

    // In order to stop the creation of any brach enter -1 as it will consider as NULL value for that node
    if(data == -1)
        return NULL;
    
    cout << "Enter the data for Left node of root node: " << endl;
    // Calling the function recursively
    root -> left = buildTree(root->left);
    cout << "Enter the data for right node of root node: " << endl;
    // Recursive Call
    root -> right = buildTree(root->right);

    return root;
}

// Level Order Traversal (BFS)
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    // Seperating level 0
    q.push(NULL);

    while (!q.empty()){
        node* temp = q.front();
        q.pop();

        // Level wise seperation. Indicates a level traversing is done.
        if(temp==NULL){
            cout << endl;

            //  There is some nodes left in the queue.
            if(!q.empty())
                q.push(NULL);
        }

        else{
            cout << temp -> data << " ";

            if(temp->left)
                q.push(temp -> left);

            if(temp->right)
                q.push(temp -> right);
        }
    }
}   

// InOrder Traversal (DFS) [Left Root Right]
void inOrder(node* root) {
    if(root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// PreOrder Traversal (DFS) [Root Left Right]
void preOrder(node* root) {
    if(root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// PostOrder Traversal (DFS) [Left Right Root]
void postOrder(node* root) {
    if(root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Create Tree from Level Order Traversal
node* buildFromLevelOrder (node* root){
    queue<node*> q;
    cout << "Enter data for root: " << endl;
    
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        
    }



}





// main function
int main(){
    node* root = NULL;

    // Creating the Tree
    root = buildTree(root);

    // BFS
    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);

    // DFS InorderTraversal
    cout << "Inorder Traversal Result is: " << endl;
    inOrder(root);

    // DFS PreOrderTraversal
    cout << "PreOrder Traversal Result is: " << endl;
    preOrder(root);

    // DFS PostOrderTraversal
    cout << "PostOrder Traversal Result is: " << endl;
    postOrder(root);

    return 0;
}
```
