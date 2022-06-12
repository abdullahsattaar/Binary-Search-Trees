# Binary-Search-Trees
C++ code to implement the Class of Binary Search Trees. Recursive insert operation, recursive inorder traversal, and some other recursive operations on BST.

Implement the following Tree Node:

template <typename k, typename v>
struct TNode
{
	 k key;
	 v value;
	 TNode<k, v> *leftChild;
	 TNode<k, v> *rightChild;
}

Now implement a binary search tree class “BST” which contains root of type TNode as data member. You have to implement the following member functions for your binary search tree:

a.	A default Constructor which sets the root to nullptr.
  
b.	A recursive “insertRec” function which is passed as parameter a key and a corresponding value. It then uses recursion to insert the <key, value> pair while considering the insertion rules. If the key already exists in the BST, it simply replaces the value. 	
void insertRec(k const  key, v const value)

c.	A function “insert” which is passed as parameter a key and a corresponding value. It then iteratively inserts the <key, value> pair while considering the insertion rules. If the key already exists in the BST, simply replace the value. 	
void insert(k const  key, v const value)

d.	A function “search” which is passed as parameter a key. The function then uses recursion to return pointer to the corresponding value. If the key does not exist, the function returns null. 
v* search(k key)

e.	A function “search” which is passed as parameter a key. The function then uses iteration to return pointer to the corresponding value. If the key does not exist, the function returns null. 
v* search(k key)

f.	A function “inorderPrintkeysRec” which prints the keys using recursive inorder traversal. 
void inorderPrintKeysRec() const

g.	A function “inorderPrintkeys” which prints the keys using iterative inorder traversal. 
void inorderPrintKeys() const

h.	A function “NoofNodes” which uses recursion to return the count of total nodes in BST. 
int NoofNodes() const

i.	A function “NoofNodes” which uses iteration to return the count of total nodes in BST. 
int NoofNodes() const


j.	A function “heightofTree” which uses recursion to return the height of BST. 
int heightofBST() const

k.	A function “heightofTree” which uses iteration to return the height of BST. 
int heightofBST() const

i. destructor


int main()
{
	BST<int, int> tree; //the key and value both are of type int

	tree.insert(500, 500);
	tree.insertRec(1000, 1000);
	tree.insert(1, 1);
	tree.insert(600, 600);
	tree.insertRec(700, 700);
	tree.insert(10, 10);
	tree.insert(30, 30);
	tree.insertRec(9000, 9000);
	tree.insert(50000, 50000);
	tree.insertRec(20, 20);


	cout << "Printing keys using iterative inorder traversal: ";
	tree.inorderPrintKeys();
	
	cout << endl << endl << "Printing keys using recursive inorder traversal: ";
	tree.inorderPrintKeysRec();

	cout << endl << endl<< "Tree Length: " << tree.length() << endl << endl;

	int *val = tree.search(1);

	if (val != nullptr)
	{
		cout << "1 found" << endl;
	}

	val = tree.search(123);

	if (val == nullptr)
	{
		cout << "123 not found" << endl;
	}

	cout <<endl<< 
	cout<<tree. NoofNodes();  //display number of nodes
	cout<<tree. heightofBST(); //display height of BST

	system("pause");
}

