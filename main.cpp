#include "BinarySearchTree.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
	try {
		BinarySearchTree<int> t(10);

		fstream f("input.txt"), f1("output.txt");
		f >> t;

		f1 << t;
		cout << t << endl;
		cout << t << endl;
		t.remove(8);
		cout << "Deleted 8. Now tree is " << endl << t << endl;
		t.remove(9);
		cout << "Deleted 9. Now tree is " << endl << t << endl;
		t.remove(15);
		cout << "Deleted 15. Now tree is " << endl << t << endl;
		t.remove(10);
		cout << "Deleted 10. Now tree is " << endl << t << endl;
		t.remove(17);
		cout << "Deleted 17. Now tree is " << endl << t << endl;
		t.remove(16);
		cout << "Deleted 16. Now tree is " << endl << t << endl;
		t.remove(20);
		cout << "Deleted 20. Now tree is " << endl << t << endl;
	}
	catch (std::invalid_argument &e) {
		cout << e.what() << endl;
	}
	catch (std::logic_error &e) {
		cout << e.what() << endl;
	}
	catch (...) {
		cout << "Something unexpected..." << endl;
	}
	system("pause");
	return 0;
}
