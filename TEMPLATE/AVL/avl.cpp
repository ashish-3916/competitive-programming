/*
Height difference of left and right subtree of node should be less than 2.
Re-balancing is done when heights of two child subtrees of a node differ by more than one.
Faster retrievals as strictly balanced.
*/

/*
1) Perform the normal BST insertion. 
2) The current node must be one of the ancestors of the newly inserted node. 
    Update the height of the current node. 
3) Get the balance factor (left subtree height – right subtree height) of the current node. 
4) If balance factor is greater than 1, then the current node is unbalanced and
   we are either in Left Left case or left Right case. To check whether it is left left case or not, 
   compare the newly inserted key with the key in left subtree root. 
5) If balance factor is less than -1, then the current node is unbalanced
   and we are either in Right Right case or Right-Left case. To check whether it is Right Right case 
   or not, compare the newly inserted key with the key in right subtree root. 

*/
class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
    // constructor -> height =1 ;
};

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
Node* insert(Node* node, int key)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                        height(node->right));
 
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);
    
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    } 
    /* return the (unchanged) node pointer */
    return node;
}
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
    // Return new root
    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    // Update heights
    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    // Return new root
    return y;
}
