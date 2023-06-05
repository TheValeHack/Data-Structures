#include <iostream>

struct Node {
	char label;
	Node* parent;
	Node* left;
	Node* right;
};

Node* root = nullptr;
Node* newNode = nullptr;

// Create New Tree
void createNewTree(const char& label) {
	if (root != nullptr) {
		std::cout << "Tree sudah dibuat" << std::endl;
	}
	else {
		root = new Node{label, nullptr, nullptr, nullptr};
		std::cout << label << " berhasil dibuat menjadi root" << std::endl;
	}
}

// Insert Left
Node* insertLeft(const char& label, Node* parent) {
	if (parent == nullptr) {
		std::cout << "Parent tidak boleh kosong" << std::endl;
		return nullptr;
	}
	else {
		newNode = new Node{ label, parent, nullptr, nullptr };
		parent->left = newNode;
		std::cout << std::endl << label << " berhasil ditambahkan ke anak kiri " << newNode->parent->label << std::endl;

		return newNode;
	}
}

// Insert Right
Node* insertRight(const char& label, Node* parent) {
	if (parent == nullptr) {
		std::cout << "Parent tidak boleh kosong" << std::endl;
		return nullptr;
	}
	else {
		newNode = new Node{ label, parent, nullptr, nullptr };
		parent->right = newNode;
		std::cout << std::endl << label << " berhasil ditambahkan ke anak kanan " << newNode->parent->label << std::endl;

		return newNode;
	}
}
// Retrieve
void retrieve(Node* node) {
	if (node == nullptr) {
		std::cout << "Node tidak boleh kosong" << std::endl;
	}
	else {
		std::cout << "\nLabel node : " << node->label << std::endl;
	}
}

// Empty
bool empty() {
	return (root == nullptr) ? true : false;
}

// Update
void update(const char& label, Node* node) {
	if (node == nullptr) {
		std::cout << "Node tidak boleh kosong" << std::endl;
	}
	else {
		char temp = node->label;
		node->label = label;

		std::cout << std::endl << temp << " berhasil diubah menjadi " << label << std::endl;
	}
}
// Find
void find(Node* node) {
	if (node == nullptr) {
		std::cout << "Node tidak boleh kosong" << std::endl;
	}
	else {
		Node* parentNode = node->parent;
		Node* leftChildNode = node->left;
		Node* rightChildNode = node->right;
		Node* siblingNode = nullptr;

		if (parentNode != nullptr) {
			if ((parentNode->left != nullptr) && (parentNode->left != node)) {
				siblingNode = parentNode->left;
			}
			else if ((parentNode->right != nullptr) && (parentNode->right != node)) {
				siblingNode = parentNode->right;
			}
			else {
				siblingNode = nullptr;
			}
		}
		

		std::cout << "================================================" << std::endl;
		std::cout << "Label node : " << node->label << std::endl;
		std::cout << "Root node : " << root->label << std::endl;
		std::cout << "Parent node : " << ( (parentNode == nullptr) ? '-' : parentNode->label) << std::endl;
		std::cout << "Sibling node : " << ( (siblingNode == nullptr) ? '-' : siblingNode->label) << std::endl;
		std::cout << "Left Child node : " << ( (leftChildNode == nullptr) ? '-' : leftChildNode->label) << std::endl;
		std::cout << "Right Child node : " << ( (rightChildNode == nullptr) ? '-' : rightChildNode->label) << std::endl;
		std::cout << "================================================" << std::endl;

	}
}
// Transversal 

// Pre Order
void preOrder(Node* node = root){
	if (node != nullptr) {
		std::cout << node->label << ", ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

// In Order
void inOrder(Node* node = root){
	if (node != nullptr) {
		inOrder(node->left);
		std::cout << node->label << ", ";
		inOrder(node->right);
	}
}

// Post Order
void postOrder(Node* node = root){
	if (node != nullptr) {
		postOrder(node->left);
		postOrder(node->right);
		std::cout << node->label << ", ";
	}
}

// Delete Sub
void deleteTree(Node* node) {
	if (node != nullptr) {
		deleteTree(node->left);
		deleteTree(node->right);
		Node* del = node;

		delete del;
	}
}
void deleteSub(Node* node) {
	deleteTree(node->left);
	deleteTree(node->right);
	node->left = nullptr;
	node->right = nullptr;

	std::cout << std::endl <<  "Subtree node " << node->label << " berhasil dihapus" << std::endl;
}

// Clear
void clear() {
	deleteTree(root);

	root = nullptr;

	std::cout << "Tree berhasil dihapus" << std::endl;
}
// Size
float checkSize(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	else {
		return 1 + checkSize(node->left) + checkSize(node->right);
	}
}
// Height
float checkHeight(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	else {
		float heightKanan = checkHeight(node->right);
		float heightKiri = checkHeight(node->left);

		if (heightKanan >= heightKiri) {
			return 1 + heightKanan;
		}
		else {
			return 1 + heightKiri;
		}
	}
}
// Characteristic

void characteristic(Node* node = root) {
	if (node != nullptr) {
		std::cout << std::endl;

		std::cout << "Node   : " << node->label << std::endl;
		// Size
		std::cout << "Size   : " << checkSize(node) << std::endl;

		// Height
		std::cout << "Height   : " << checkHeight(node) - 1 << std::endl;

		// Average
		std::cout << "Average   : " << checkSize(node)/checkHeight(node) << std::endl;


		std::cout << std::endl;

	}
	else {
		std::cout << "Tree tidak boleh kosong" << std::endl;
	}
}

// Main Function
int main() {
	createNewTree('A');

	Node *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

	nodeB = insertLeft('B', root);
	nodeC = insertRight('C', root);
	nodeD = insertLeft('D', nodeB);
	nodeE = insertRight('E', nodeB);
	nodeF = insertLeft('F', nodeC);
	nodeG = insertLeft('G', nodeE);
	nodeH = insertRight('H', nodeE);
	nodeI = insertLeft('I', nodeG);
	nodeJ = insertRight('J', nodeG);

	update('Z', nodeC);
	update('C', nodeC);

	retrieve(nodeC);

	find(nodeC);


	std::cout << std::endl;

	std::cout << "Pre Order : ";
	preOrder();

	std::cout << std::endl;

	std::cout << "In Order : ";
	inOrder();

	std::cout << std::endl;

	std::cout << "Post Order : ";
	postOrder();

	std::cout << std::endl;


	deleteSub(nodeC);


	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << "Pre Order : ";
	preOrder();

	std::cout << std::endl;

	std::cout << "In Order : ";
	inOrder();

	std::cout << std::endl;

	std::cout << "Post Order : ";
	postOrder();

	std::cout << std::endl;
	std::cout << std::endl;


	characteristic();
	std::cout << std::endl;

	characteristic(nodeC);

	std::cout << std::endl;

	clear();

	std::cout << std::endl;

	std::cout << "Pre Order : ";
	preOrder();

	std::cout << std::endl;

	std::cout << "In Order : ";
	inOrder();

	std::cout << std::endl;

	std::cout << "Post Order : ";
	postOrder();

	std::cout << std::endl;

	std::cout << std::endl;


	std::cout << "\nTree empty? : " << empty() << std::endl;

	return 0;
}
