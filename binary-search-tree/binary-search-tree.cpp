#include "stdafx.h"
#include "BinarySearchTree.h"

using std::cout;
using std::cin;
using std::endl;

int main() {	
	try {
		BinarySearchTree<size_t> t(6);

		fstream f("test.txt"), f1("more.txt");
		f >> t;

		f1 << t;

		cout << t.search(1) << endl;
		cout << t.search(4) << endl;
		cout << t.search(12) << endl;
	}
	catch (...) {
		cout << "errors";
	}
	
	system("pause");
	return 0;
}