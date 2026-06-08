#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int diameterUtil(Node* root, int &diameter) {
    if (root == NULL) return 0;
    int leftHeight = diameterUtil(root->left, diameter);
    int rightHeight = diameterUtil(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return max(leftHeight, rightHeight) + 1;
}

int diameter(Node* root) {
    int dia = 0;
    diameterUtil(root, dia);
    return dia;
}

int main() {
    cout << "\n=== PROGRAM HITUNG JARAK TERJAUH BST ===\n";
    cout << "Masukkan input:\n";
    cout << "Baris 1: N (jumlah elemen)\n";
    cout << "Baris 2: N elemen unik\n";
    cout << "Output: Jarak terjauh antar node (diameter)\n";
    cout << "=========================================\n\n";

    int N;
    cout << "Masukkan N: ";
    cin >> N;
    Node* root = NULL;
    cout << "Masukkan " << N << " elemen: ";
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        root = insert(root, x);
    }

    cout << "\nDiameter BST (jarak terjauh) = " << diameter(root) << endl;
    return 0;
}