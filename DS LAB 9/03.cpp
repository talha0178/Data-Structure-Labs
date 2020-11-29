
/*The following program simply inserts, deletes nodes from the the tree, later with a help of CONVERT_AVL function
 the BST is converted into AVL tree. In addition to this the program is also capable of displaying the tree.*/

#include <iostream>
using namespace std;

const int SPACE = 5;


class TreeNode {    
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    
    

    TreeNode() {
        value = 0;
        left = NULL;
        right = NULL;
      
    }
    TreeNode(int v) {
        value = v;
        left = NULL;
        right = NULL;
      
    }
};


class AVL
{
private:
    int h;
    bool ifAVL;
   
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        /* loop down to find the leftmost leaf */
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }
public:
    int numOfNodes;
    AVL()
    {
        h = 0;
        ifAVL = true;
        numOfNodes = 0;
    }
    //For inserting nodes in the AVL Tree
    TreeNode* insert(TreeNode* root, int value)
    {
        if (root == NULL)
        {
            root = new TreeNode;
            root->value = value;
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        else if (value < root->value)
        {
            root->left = insert(root->left, value);
            //root = balance(root);
        }
        else if (value >= root->value)
        {
            root->right = insert(root->right, value);
            //root = balance(root);
        }
        numOfNodes++;
        return root;

    }

    TreeNode* deleteNode(TreeNode* r, int v) {
        // base case 
        if (r == NULL) {
            return NULL;
        }
       
        else if (v < r->value) {
            r->left = deleteNode(r->left, v);
        }
        
        else if (v > r->value) {
            r->right = deleteNode(r->right, v);
        }
       
        else {
            // node with only one child or no child 
            if (r->left == NULL) {
                TreeNode* temp = r->right;
                delete r;
               
                return temp;
            }
            else if (r->right == NULL) {
                TreeNode* temp = r->left;
                delete r;
                
                return temp;
            }
            else {
                // node with two children: Get the inorder successor (smallest 
                // in the right subtree) 
                TreeNode* temp = minValueNode(r->right);
                // Copy the inorder successor's content to this node 
                r->value = temp->value;
                // Delete the inorder successor 
                r->right = deleteNode(r->right, temp->value);
               
            }
           
        }

        //After the deletion of node same as Binary search tree, the line below performs the required rotations to
        // ensure the BST is Balanced
       //r = balance(r);
        numOfNodes--;
        return r;
    }

    TreeNode* CONVERT_AVL(TreeNode* r)
    {      
        return r = balance(r);
    }
        //Calculates the height of the node
        int height(TreeNode * r) {
            if (r == NULL)
                return -1;
            else {
                // compute the height of each subtree 
                int lheight = height(r->left);
                int rheight = height(r->right);

               
                if (lheight > rheight)
                    return (lheight + 1);
                else return (rheight + 1);
            }
        }


        //diff = Left height - Right height

        int diff(TreeNode * temp)
        {
            int l_height = height(temp->left);
            int r_height = height(temp->right);
            int b_factor = l_height - r_height;
            return b_factor;
        }


        //The following function performs preorder traversal on the tree and checks the balancing factor for each node
        //If it exceeds 1 or -1 the program it displays not AVL if not it displays AVL with the help of AvlOrNot()
        void chkAVL(TreeNode* r)
        {
            if (r == NULL)
                return;
            h = diff(r);
            if (h > -1 || h > 1)
            {
                ifAVL = false;
                return;
            }
            chkAVL(r->left);
            chkAVL(r->right);
        }

      

       //It only displays the result and calls chkAVL
        bool AvlOrNot(TreeNode* r)
        {
            chkAVL(r);
            return ifAVL;
        }
        //This function determines the balance factor so later 
        //on we can perform the required rotations to balance the tree

        TreeNode* balance(TreeNode * temp)
        {
            int bal_factor = diff(temp);
            if (bal_factor > 1)
            {
                if (diff(temp->left) > 0)
                    temp = ll_rotation(temp);
                else
                    temp = lr_rotation(temp);
            }
            else if (bal_factor < -1)
            {
                if (diff(temp->right) > 0)
                    temp = rl_rotation(temp);
                else
                    temp = rr_rotation(temp);
            }
            return temp;
        }

        //Right Right Rotation
        TreeNode* rr_rotation(TreeNode * node)
        {
            TreeNode* temp;
            temp = node->right;
            node->right = temp->left;
            temp->left = node;
            return temp;
        }


        //Left Left Rotation
        TreeNode* ll_rotation(TreeNode * node)
        {
            TreeNode* temp;
            temp = node->left;
            node->left = temp->right;
            temp->right = node;
            return temp;
        }


        //Left Right Rotation
        TreeNode* lr_rotation(TreeNode * node)
        {
            TreeNode* temp;
            temp = node->left;
            node->left = rr_rotation(temp);
            return ll_rotation(node);
        }


        //Right Left Rotation
        TreeNode* rl_rotation(TreeNode * node)
        {
            TreeNode* temp;
            temp = node->right;
            node->right = ll_rotation(temp);
            return rr_rotation(node);
        }


        /*The function displays the AVL tree on the console inverted 90 degrees*/
        void displayAVL(TreeNode* r, int space) {
            if (r == NULL) 
                return;
            space += SPACE; 
            displayAVL(r->right, space); 
            cout << endl;
            for (int i = SPACE; i < space; i++) 
                cout << " ";  
            cout << r->value << "\n"; 
            displayAVL(r->left, space); 
        };

    
};


int main()
{
    int choice, n;
    AVL T1;
    TreeNode* root = NULL;
    root =  T1.insert(root, 10);
    root =  T1.insert(root, 20);
    root =  T1.insert(root, 30);
    root =  T1.insert(root, 40);
    root =  T1.insert(root, 50);

    while (1)
    {
        
        cout << "\n\t|||| BST Tree ||||\t" << endl << endl;
       
        cout << "1. Insert Element into the tree" << endl;
        cout << "2. Delete Element from the tree" << endl;
        cout << "3. CONVERT TO AVL" << endl;
        cout << "4. Display TREE" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your Choice: ";
        cout << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> n;
            root = T1.insert(root, n);
            break;
        case 2:
            cout << "Enter value to be deleted: " << endl;
            cin >> n;
            root = T1.deleteNode(root, n);
            break;
        case 3:  
            cout << "\n Tree is Successfully converted into AVL!" << endl;
           for(int i = 0; i < T1.numOfNodes; i++)
                root = T1.CONVERT_AVL(root);         
            break;
        case 4:
            if (root == NULL)
            {
                cout << "Tree is Empty" << endl;
                continue;
            }
            cout << "AVL Tree:" << endl;
            T1.displayAVL(root, 1);
            break;    
           
        case 5:
            exit(1);
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
        cout << "__________________________________________________________________________________________________\n";
    }
    return 0;
}
