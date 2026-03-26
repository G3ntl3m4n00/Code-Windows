#include <iostream>
#include <fstream>

// Binary Search Tree
// 1. Exercise - Making a binary tree from file

/**
 * Represents a single node in the binary search tree.
 * Each node holds an integer value and pointers to its left and right subtrees.
 * Left subtree contains values less than root; right contains values >= root.
 */
struct binaryTree {
    int root;         // The value stored in this node
    binaryTree *left; // Pointer to the left child (smaller values)
    binaryTree *right;// Pointer to the right child (greater or equal values)
};

binaryTree *tree = nullptr; // Pointer to the root node of the BST; nullptr means empty tree
int num_of_nodes;           // Number of nodes to be read from the input file


/**
 * Inserts a new value into the binary search tree.
 *
 * @param current_tree  Reference to the pointer of the current node being examined.
 *                      Passed by reference so the pointer itself can be modified
 *                      when a new node is created.
 *
 * @param a             The integer value to insert.
 *
 */
void insert (binaryTree *& current_tree, const int a) {
    if (current_tree == nullptr) {
        auto *new_tree = new binaryTree;

        new_tree->root = a;         // Assign the value to the new node
        new_tree->left = nullptr;   // Initialize left child as empty
        new_tree->right = nullptr;  // Initialize right child as empty
        current_tree = new_tree;    // Link the new node into the tree
    }
    else {
        // Traverse left if value is smaller, right if greater or equal
        if (a < current_tree->root)
            insert(current_tree->left, a);
        else
            insert(current_tree->right, a);
    }
}


/**
 * Reads integers from "tree.in" and inserts them into the BST.
 *
 * Expected file format:
 *   Line 1: an integer N (number of nodes)
 *   Line 2+: N space-separated integers to insert
 *
 * Example:
 *   5
 *   10 5 15 3 7
 */
void readFromFile () {
    std::ifstream input_file("tree.in");

    input_file >> num_of_nodes; // Read the total number of values to insert

    for (int i = 0; i < num_of_nodes; i++) {
        int a;
        input_file >> a;    // Read the next value
        insert(tree, a);    // Insert it into the BST
    }
}

/**
 * Prints the BST contents to stdout using pre-order traversal (root, left, right).
 * Output values are space-separated on a single line.
 *
 * @param current_tree  Pointer to the current node being visited.
 *
 */
void PreOrder_BST_Console(const binaryTree *current_tree) {
   if (current_tree != nullptr) {           // BUG: should be `current_tree != nullptr`
       std::cout << current_tree->root << " "; // Print current node's value
       PreOrder_BST_Console(current_tree->left);  // Recurse into left subtree
       PreOrder_BST_Console(current_tree->right); // Recurse into right subtree
   }
}


/**
 * Prints the BST contents to stdout using in-order traversal (left, root, right).
 * Output values are space-separated on a single line.
 *
 * @param current_tree  Pointer to the current node being visited.
 *
 */
void InOrder_BST_Console(const binaryTree *current_tree) {
    if (current_tree != nullptr) {
        InOrder_BST_Console(current_tree->left);
        std::cout << current_tree->root << " ";
        InOrder_BST_Console(current_tree->right);
    }
}

/**
 * Prints the BST contents to stdout using post-order traversal (left, right, root).
 * Output values are space-separated on a single line.
 *
 * @param current_tree  Pointer to the current node being visited.
 *
 */
void PostOrder_BST_Console(const binaryTree *current_tree) {
    if (current_tree != nullptr) {
        PostOrder_BST_Console(current_tree->left);
        PostOrder_BST_Console(current_tree->right);
        std::cout << current_tree->root << " ";
    }
}


int main() {
    readFromFile();                  // Build the BST from file

    std::cout << "Preorder:\n";
    PreOrder_BST_Console(tree);      // Print the BST in pre-order
    std::cout << std::endl;

    std::cout << "In-order:\n";
    InOrder_BST_Console(tree);      // Print the BST in in-order
    std::cout << std::endl;


    std::cout << "Post-order:\n";
    PostOrder_BST_Console(tree);    // Print the BST in post-order
    std::cout << std::endl;
}