#include <iostream>
#include <fstream>


struct binaryTree {
    int root;
    binaryTree *left;
    binaryTree *right;
};

binaryTree *binary_search_tree{nullptr};

static void insert(binaryTree *&current_tree, const int insert_num) {
    if (current_tree == nullptr) {
        auto *new_tree = new binaryTree;
        new_tree->root = insert_num;
        new_tree->right = nullptr;
        new_tree->left = nullptr;

        current_tree = new_tree;
    }
    else {
        if (current_tree->root > insert_num)
            insert(current_tree->left, insert_num);
        else
            insert(current_tree->right, insert_num);
    }
}


void readFromFile(const char *file_name) {
    std::ifstream input_file(file_name);

    int num_of_nodes;
    input_file >> num_of_nodes;

    for (int i = 0; i < num_of_nodes; i++) {
        int a;
        input_file >> a;
        insert(binary_search_tree, a);
    }
}

void Inorder_BST_Console(const binaryTree *current_tree) {
    if (current_tree != nullptr) {
        Inorder_BST_Console(current_tree->left);
        std::cout << current_tree->root << " ";
        Inorder_BST_Console(current_tree->right);
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

void level(const binaryTree *current_tree, const int current_level, const int write_level) {
    if (current_tree != nullptr) {
        if (current_level == write_level)
            std::cout << current_tree->root << " ";
        else if (current_level < write_level) {
            level(current_tree->left, current_level + 1, write_level);
            level(current_tree->right, current_level + 1, write_level);
        }
    }
}

int main() {
    const auto file_name {"tree.in"};

    readFromFile(file_name);

    std::cout << "Preorder:\n";
    PreOrder_BST_Console(binary_search_tree);      // Print the BST in pre-order
    std::cout << std::endl;

    std::cout << "In-order:\n";
    InOrder_BST_Console(binary_search_tree);      // Print the BST in in-order
    std::cout << std::endl;


    std::cout << "Post-order:\n";
    PostOrder_BST_Console(binary_search_tree);    // Print the BST in post-order
    std::cout << std::endl;

    std::cout << "The level you would like to watch:\n";
    int watch_level;
    std::cin >> watch_level;

    std::cout << "Elements from the give level:\n";
    level(binary_search_tree, 1, watch_level);
    std::cout << std::endl;
}