#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node structure
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman Codes
void printCodes(Node* root, string str) {
    if (!root)
        return;

    // If leaf node
    if (root->data != '$')
        cout << root->data << " : " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Function to build Huffman Tree
void HuffmanCodes(char data[], int freq[], int size) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes
    for (int i = 0; i < size; i++) {
        pq.push(new Node(data[i], freq[i]));
    }

    // Build tree
    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Print codes
    printCodes(pq.top(), "");
}

// Main function
int main() {
    char data[] = {'A', 'B', 'C', 'D', 'E'};
    int freq[] = {5, 9, 12, 13, 16};

    int size = sizeof(data) / sizeof(data[0]);

    cout << "Huffman Codes:\n";
    HuffmanCodes(data, freq, size);

    return 0;
}