#include <iostream>
#include <random>

/**
 *  @date 2026. March. 20.
 *  @brief Binary Search Tree - Exercise
 */

/**
 * @note Random number between -100 and 100, n pieces,
 *       Insert the values into a binary search tree,
 *       Traverse it with in-order, printing the values in ascending order.
 */


/**
 * Represents a single node in the binary search tree.
 * Left subtree contains values less than root; right contains values >= root.
 */
struct binaryTree {
    int root;          // The value stored in this node
    binaryTree *left;  // Pointer to the left child (smaller values)
    binaryTree *right; // Pointer to the right child (greater or equal values)
};

binaryTree *tree = nullptr; // Pointer to the root node of the BST; nullptr means empty tree


/**
 * Recursively inserts a value into the binary search tree.
 *
 * @param current_tree  Reference to the pointer of the current node being examined.
 *                      Passed by reference so a new node can be linked in place.
 * @param a             The integer value to insert.
 */
void insert(binaryTree *&current_tree, const int a) {
    if (current_tree == nullptr) {        // Base case: empty spot found, insert here
        auto *new_tree = new binaryTree;
        new_tree->root = a;               // Assign the value to the new node
        new_tree->left = nullptr;         // Initialize left child as empty
        new_tree->right = nullptr;        // Initialize right child as empty
        current_tree = new_tree;          // Link the new node into the tree
    }
    else {
        if (a < current_tree->root)
            insert(current_tree->left, a);  // Value is smaller, go left
        else
            insert(current_tree->right, a); // Value is greater or equal, go right
    }
}


/**
 * Generates n random integers in the range [-100, 100] and inserts them into the BST.
 * Prompts the user for n, then prints the numbers in generation order.
 */
void generate() {
    std::random_device rd;                        // Non-deterministic seed source
    std::mt19937 gen(rd());                       // Mersenne Twister engine seeded with rd
    std::uniform_int_distribution<> dist(-100, 100); // Uniform distribution over [-100, 100]

    int n;
    std::cout << "How many elements should the binary search tree should have?\n";
    std::cin >> n;

    std::cout << "Elements in generation order:\n";
    for (int i = 0; i < n; i++) {
        int a = dist(gen);   // Generate a random number in [-100, 100]
        insert(tree, a);     // Insert it into the BST
        std::cout << a << " ";
    }
    std::cout << '\n';
}

/**
 * Prints the BST contents to stdout using in-order traversal (left, root, right).
 * Since this is a BST, in-order traversal produces values in ascending sorted order.
 *
 * @param current_tree  Pointer to the current node being visited.
 */
void InOrder_BST_Console(const binaryTree *current_tree) {
    if (current_tree != nullptr) {
        InOrder_BST_Console(current_tree->left);  // Recurse into left subtree first
        std::cout << current_tree->root << " ";   // Print current node's value
        InOrder_BST_Console(current_tree->right); // Recurse into right subtree last
    }
}


int main() {
    generate();                      // Build the BST from randomly generated values

    std::cout << "In-order:\n";
    InOrder_BST_Console(tree);       // Print the BST in ascending order
    std::cout << std::endl;
}