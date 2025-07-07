#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (!node) return nullptr;
        if (key < node->data) node->left = deleteNode(node->left, key);
        else if (key > node->data) node->right = deleteNode(node->right, key);
        else {
            if (!node->left) return node->right;
            if (!node->right) return node->left;

            Node* successor = minValueNode(node->right);
            node->data = successor->data;
            node->right = deleteNode(node->right, successor->data);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void deleteVal(int val) {
        root = deleteNode(root, val);
    }

    void update(int oldVal, int newVal) {
        root = deleteNode(root, oldVal);
        root = insert(root, newVal);
    }

    void printInorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void printPreorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    void printPostorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice;

    cout << "Binary Search Tree CRUD Tool\n";

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Update\n4. Inorder\n5. Preorder\n6. Postorder\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            tree.insert(val);
        }
        else if (choice == 2) {
            int val;
            cout << "Enter value to delete: ";
            cin >> val;
            tree.deleteVal(val);
        }
        else if (choice == 3) {
            int oldVal, newVal;
            cout << "Enter old value: ";
            cin >> oldVal;
            cout << "Enter new value: ";
            cin >> newVal;
            tree.update(oldVal, newVal);
        }
        else if (choice == 4) tree.printInorder();
        else if (choice == 5) tree.printPreorder();
        else if (choice == 6) tree.printPostorder();
        else if (choice == 7) break;
        else cout << "Invalid choice. Try again.\n";
    }

    return 0;
}
