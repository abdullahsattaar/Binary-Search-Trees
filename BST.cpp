#include<iostream>
using namespace std;

template <typename k, typename v>
class TNode
{
public:
	 k key;
	 v value;
	 TNode<k, v> *leftChild;
	 TNode<k, v> *rightChild;

	 TNode(k ke, v val)
	 {
		 key=ke;
		 value=val;
		 leftChild=nullptr;
		 rightChild=nullptr;
	 }

};
template<typename k, typename v>
class BST
{
	TNode<k,v> *root;
public:
	//Constructor
	BST()
	{
		root=nullptr;
	}

	//Recusrsive Insertion
	void insertR(k const  ke, v const val, TNode<k,v> *&node)
	{
		if(node==NULL)
		{
			node = new TNode<k,v>(ke,val);
		}
		else if(node->key > ke)
			insertR(ke,val,node->leftChild);
		else
			insertR(ke,val,node->rightChild);
	}
	void insertRec(k const  ke, v const val)
	{
		insertR(ke,val,root);
	}

	//Iterative Insertion
	void insertI(k const  ke, v const val)
	{
		TNode <k,v> * newNode = new TNode<k,v>(ke,val);
		TNode <k,v> * parent = root;
		TNode <k,v> * child = root;
		while (child)
		{
			parent = child;
			if (parent->key>ke)
				child = child->leftChild;
			else if (parent ->key <= ke)
			child = child->rightChild;
		}
		if (parent == NULL)
			root = newNode;
		else if (parent->key > ke)
			parent->leftChild = newNode;
		else if (parent->key <= ke)
			parent->rightChild = newNode;
	}

	//Recursive Search
	v* searchR(TNode <k,v> * node, k ke)
	{
		if (node) 
		{
			if (node ->key > ke)
				searchR(node ->leftChild, ke);
			else if (node ->key < ke)
				searchR(node ->rightChild, ke);
			else
				return &(node->value);
		}
		else
			return nullptr;
	}
	v* searchRec(k ke)
	{
		return searchR(root,ke);
	}

	//Iterative Search
	v* searchI(k ke)
	{
		TNode <k,v>* iter = root;
		while (iter && !flag)
		{
			if (iter ->key == ke)
				return iter->value;
			else if (iter->key > ke)
				iter= iter->leftChild;
			else
				iter= iter->rightChild;
		}
		return nullptr;
	}

	//Recursive Print
	void InOrder(TNode<k,v>* t)
	{
		if (t)
		{
			InOrder(t->leftChild);
			cout << t->key<<" ";
			InOrder(t->rightChild);
		}
	}
	void inorderPrintKeysRec() 
	{
		TNode<k,v> * t=root;
		InOrder(t);
	}

	//Iterative Print
	void inorderPrintKeys() const
	{
		TNode<k,v> *newNode =root;
	}

	//Recursive No of Nodes
	int noofnodesR(int & count, TNode<k,v>* t)
	{
		if(t)
		{
		    noofnodesR(count,t->leftChild);
			count++;
			noofnodesR(count,t->rightChild);
		}
		return count;
	}
	int NoofNodesR()
	{
		int count=0;
		//TNode<k,v> * t=root;
		return noofnodesR(count,root);
	}

	//Iterative No of Nodes
	int NoofNodesI() const
	{

	}

	//Recursive Height of BST
	int heightR(TNode<k,v> *t, int H)
	{
		int count2=0;
		if (t)
		{
			int heightL= heightR(t->leftChild,0);
			int heightRi=heightR(t->rightChild,0);
			if (heightL>heightRi)
				count2=heightL;
			else 
				count2=heightRi;
		}
			if (count2>H)
				H=count2;
			return H;

	}
	int heightofBSTRec()
	{
		return heightR(root,0);
	}

	//Destructor
	void Destructor(TNode<k,v>*tmp)
	{
		if(tmp)
		{
			Destructor(tmp->leftChild);
			Destructor(tmp->rightChild);
			delete tmp;
		}
	}
	~BST()
	{
		Destructor(root);
	}
};


int main()
{
	BST<int, int> tree; //the key and value both are of type int

	tree.insertI(500, 500);
	tree.insertRec(1000, 1000);
	tree.insertI(1, 1);
	tree.insertI(600, 600);
	tree.insertRec(700, 700);
	tree.insertI(10, 10);
	tree.insertI(30, 30);
	tree.insertRec(9000, 9000);
	tree.insertI(50000, 50000);
	tree.insertRec(20, 20);


	cout << "Printing keys using iterative inorder traversal: ";
	tree.inorderPrintKeys();
	
	cout << endl << endl << "Printing keys using recursive inorder traversal: ";
	tree.inorderPrintKeysRec();

	//cout << endl << endl<< "Tree Length: " << tree.length() << endl << endl;

	int *val = tree.searchRec(1);

	if (val != nullptr)
	{
		cout << "1 found" << endl;
	}

	val = tree.searchRec(123);

	if (val == nullptr)
	{
		cout << "123 not found" << endl;
	}

	cout <<endl<< 
		cout<<tree.NoofNodesR();  //display number of nodes
	cout<<tree. heightofBSTRec(); //display height of BST

	system("pause");
	return 0;
}

