/*
* @file Binary Search Tree
* @author Nguyen Trieu Thien Hao
* @date 2020-12-12
*/
#include<iostream>
#include<vector>
using namespace std;


class NODE {
public:
	int	data;
	NODE* pLeft;
	NODE* pRight;

	NODE(int data) {
		this->data = data;
		this->pLeft = NULL;
		this->pRight = NULL;
	}
};

class TREE {
private:
	NODE* pRoot;

	/********************************************************************
	*							IMPLEMENTATION							*
	*								BEGIN								*
	*********************************************************************/

	// Traveresal - duyet
	// Pre-order Traversal - NLR : duyet tien tu
	void NLR(NODE* pRoot) {
		if (pRoot != NULL) {
			//implement pRoot
			cout << pRoot->data << " ";
			NLR(pRoot->pLeft);
			NLR(pRoot->pRight);
		}
	}
	// In-order Traversal - NLR : duyet trung tu
	void LNR(NODE* pRoot) {
		if (pRoot != NULL) {
			LNR(pRoot->pLeft);
			//implement pRoot
			cout << pRoot->data << " ";
			LNR(pRoot->pRight);
		}
	}
	// Post-order Traversal - NLR : duyet hau tu
	void LRN(NODE* pRoot) {
		if (pRoot != NULL) {
			LRN(pRoot->pLeft);
			LRN(pRoot->pRight);
			//implement pRoot
			cout << pRoot->data << " ";
		}
	}

	//Destroy TREE
	void destroyTree(NODE* pRoot) {
		//using LRN
		if (pRoot != NULL) {
			destroyTree(pRoot->pLeft);
			destroyTree(pRoot->pRight);
			delete	pRoot;
		}
	}

	//Insert NODE into the TREE
	void addNode(NODE*& pRoot, NODE* pNew) {
		//using NLR
		if (pRoot == NULL) {
			pRoot = pNew;
		}
		else if (pNew->data == pRoot->data) {
			cerr << "trung gia tri";
		}
		else if (pNew->data < pRoot->data) {
			addNode(pRoot->pLeft, pNew);
		}
		else {
			addNode(pRoot->pRight, pNew);
		}
	}

	// Search NODE in the TREE
	NODE* findNode(NODE* pRoot, int data) {
		//using NLR
		if (pRoot == NULL) {
			return NULL;
		}
		else if (pRoot->data == data) {
			return pRoot;
		}
		else if (data < pRoot->data) {
			return findNode(pRoot->pLeft, data);
		}
		else {
			return findNode(pRoot->pRight, data);
		}
	}

	/********************************************************************
	*							IMPLEMENTATION							*
	*								  END								*
	*********************************************************************/

public:
	// constructor 
	TREE() {
		this->pRoot = NULL;
	}
	// destructor
	~TREE() {
		destroyTree(this->pRoot);
	}

	/********************************************************************
	*								INTERFACE							*
	*								  BEGIN								*
	*********************************************************************/

	void buildTree(vector<int> values) {
		for (auto data : values) {
			this->insertNode(data);
		}
	}
	/* 
	// Dont use vector 
	void buildTree() {
		int size;
		cout << "nhap so node: ";
		cin >> size;
		for (int i = 0; i < size; i++) {
			int data;
			cout << "nhap data NODE[" << i << "]: ";
			cin >> data;
			this->insertNode(data);
	}
	*/
	void tranversePreOrder() {
		// Pre-order Traversal - NLR : duyet tien tu
		NLR(this->pRoot);
	}

	void tranverseInOrder() {
		// In-order Traversal - NLR : duyet trung tu
		LNR(this->pRoot);
	}

	void tranversePostOrder() {
		// Post-order Traversal - NLR : duyet hau tu
		LRN(this->pRoot);
	}


	void insertNode(int data) {
		//Insert NODE into the TREE
		NODE* pNew = new NODE(data);
		addNode(this->pRoot, pNew);
	}

	NODE* searchNode(int data) {
		//Search NODE in the TREE
		return findNode(this->pRoot, data);
	}

	/********************************************************************
	*								INTERFACE							*
	*								  END								*
	*********************************************************************/
};

int main() {
	TREE t;
	vector<int> values = { 9,5,7,99,3 };
	t.buildTree(values);
	t.tranversePreOrder();
	cout << "\n";
	return 0;
}