#include <iostream>
#include <fstream>

struct binaryTree {
    int root;
    binaryTree *left;
    binaryTree *right;
};


binaryTree *tree;
int num_of_nodes;


void insert(binaryTree *&current_tree, const int a) {
    if (current_tree == nullptr) {
        auto *new_tree = new binaryTree;
        new_tree->root = a;
        new_tree->left = nullptr;
        new_tree->right = nullptr;

        current_tree = new_tree;
    }
    else {
        if (a < current_tree->root)
            insert(current_tree->left, a);
        else
            insert(current_tree->right, a);
    }
}

void readFromFile() {
    std::ifstream input_file("preorder.in");
    input_file >> num_of_nodes;

    for (int i = 0; i < num_of_nodes; i++) {
        int a;
        input_file >> a;
        insert(tree, a);
    }
}


void PreOrder_BST_Console(const binaryTree *current_tree) {
    if (current_tree != nullptr) {
        std::cout << current_tree->root << " ";
        PreOrder_BST_Console(current_tree->left);
        PreOrder_BST_Console(current_tree->right);
    }
}

void InOrder_BST_Console(const binaryTree *current_tree) {
    if (current_tree != nullptr) {
        InOrder_BST_Console(current_tree->left);
        std::cout << current_tree->root << " ";
        InOrder_BST_Console(current_tree->right);
    }
}

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


bool searchForElement(const binaryTree *current_tree, const int element) {
    if (current_tree != nullptr) {
        if (current_tree->root == element)
            return true;
        if (element < current_tree->root)
            return searchForElement(current_tree->left, element);
        return searchForElement(current_tree->right, element);
    }
    return false;
}


int main() {
    readFromFile();


    std::cout << "Pre-order:\n";
    PreOrder_BST_Console(tree);
    std::cout << std::endl;

    std::cout << "In-order:\n";
    InOrder_BST_Console(tree);
    std::cout << std::endl;

    std::cout << "Post-order:\n";
    PostOrder_BST_Console(tree);
    std::cout << std::endl;


    std::cout << "The level you would like to watch:\n";
    int watch_level;
    std::cin >> watch_level;

    std::cout << "Elements from the give level:\n";
    level(tree, 1, watch_level);
    std::cout << std::endl;


    std::cout << "The element you would like to search for:\n";
    int search_element;
    std::cin >> search_element;

    std::cout << (searchForElement(tree, search_element) ? "The element is in the BST." : "The element isn't in the tree.") << "\n";

}
