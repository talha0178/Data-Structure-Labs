
/*The following program takes two AVL trees and merges them into a single tree and 
displays them on the console in a preorder manner
*/

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
             root = balance(root);
         }
         else if (value >= root->value)
         {
             root->right = insert(root->right, value);
             root = balance(root);
         }
         numOfNodes++;
         return root;

     }

     TreeNode* deleteNode(TreeNode* r, int v) {
         // base case 
         if (r == NULL) {
             return NULL;
         }
         // If the key to be deleted is smaller than the root's key, 
         // then it lies in left subtree 
         else if (v < r->value) {
             r->left = deleteNode(r->left, v);
         }
         // If the key to be deleted is greater than the root's key, 
         // then it lies in right subtree 
         else if (v > r->value) {
             r->right = deleteNode(r->right, v);
         }
         // if key is same as root's key, then This is the node to be deleted 
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

         r = balance(r);
         numOfNodes--;
         return r;
     }
     //Calculates the height of the node
     int height(TreeNode* r) {
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

     int diff(TreeNode* temp)
     {
         int l_height = height(temp->left);
         int r_height = height(temp->right);
         int b_factor = l_height - r_height;
         return b_factor;
     }


    

    
     //This function determines the balance factor so later 
     //on we can perform the required rotations to balance the tree

     TreeNode* balance(TreeNode* temp)
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
     TreeNode* rr_rotation(TreeNode* node)
     {
         TreeNode* temp;
         temp = node->right;
         node->right = temp->left;
         temp->left = node;
         return temp;
     }


     //Left Left Rotation
     TreeNode* ll_rotation(TreeNode* node)
     {
         TreeNode* temp;
         temp = node->left;
         node->left = temp->right;
         temp->right = node;
         return temp;
     }


     //Left Right Rotation
     TreeNode* lr_rotation(TreeNode* node)
     {
         TreeNode* temp;
         temp = node->left;
         node->left = rr_rotation(temp);
         return ll_rotation(node);
     }


     //Right Left Rotation
     TreeNode* rl_rotation(TreeNode* node)
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

 TreeNode* MergeTrees(TreeNode* t1, TreeNode* t2)
 {
     if (!t1)
         return t2;
     if (!t2)
         return t1;
     t1->value = t1->value + t2->value;
     t1->left = MergeTrees(t1->left, t2->left);
     t1->right = MergeTrees(t1->right, t2->right);
     return t1;
 }

 int main()
 {
     int tNodes = 0;
     AVL T1, T2, T3;
     TreeNode* r1 = NULL;
     TreeNode* r2 = NULL;
     
     r1 = T1.insert(r1, 50);
     r1 = T1.insert(r1, 40);
     r1 = T1.insert(r1, 60);


     r2 = T2.insert(r2, 80);
     r2 = T2.insert(r2, 70);
     r2 = T2.insert(r2, 90);

     tNodes = T1.numOfNodes + T2.numOfNodes;

     cout << "Tree 1: " << endl;
     T1.displayAVL(r1,5);

     cout << "\n\n\n";

     cout << "Tree 2: " << endl;
     T2.displayAVL(r2, 5);

     
     

     cout << "\n\n\n";
     TreeNode* r3 = MergeTrees(r1, r2);
     cout << "MERGED TREE: " << endl;
     T3.displayAVL(r3, 5);
   
     cout << endl << endl;
     system("pause");
     return 0;
 }




