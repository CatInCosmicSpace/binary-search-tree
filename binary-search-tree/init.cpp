#include "BinarySearchTree.h"
#include <catch.hpp>
#include <fstream>

SCENARIO("Tree: init, getCount(), getNumber()", "[init, getCount(), getNumber()]") {
	BinarySearchTree<size_t> b1, b2(2);

	REQUIRE(b1.getCount() == 0);
	REQUIRE(b2.getCount() == 2);
	REQUIRE(b1.getNumber() == 0);
	REQUIRE(b2.getNumber() == 0);
}

SCENARIO("Tree: init with initializer list", "[init]") {
	BinarySearchTree<int> tree = { 8 };

	REQUIRE(tree.getNumber() == 1);
}

SCENARIO("Tree: search non inserted element", "[search]") {
	BinarySearchTree<int> tree = { 8, 4, 3 };
	bool flag = false;
	try {
		tree.search(5);
	}
	catch (std::invalid_argument) {
		flag = true;
	}

	REQUIRE(flag);
}

SCENARIO("Tree: delete non inserted element", "[delete]") {
	BinarySearchTree<int> tree = { 8 };
	bool flag = false;
	try {
		tree.remove(5);
	}
	catch (std::invalid_argument) {
		flag = true;
	}

	REQUIRE(flag);
}

SCENARIO("Tree: insert element", "[insert]") {
	BinarySearchTree<size_t> b1;

	REQUIRE(b1.insert(1));
}

SCENARIO("Tree: search", "[search]") {
	BinarySearchTree<size_t> b;
	b.insert(1);
	b.insert(2);
	b.insert(13);

	REQUIRE(b.search(1) != nullptr);
	REQUIRE(b.search(2) != nullptr);
	REQUIRE(b.search(13) != nullptr);
}

SCENARIO("Tree: operator >>", "[file and stream input]") {
	BinarySearchTree<size_t> b(10);
	fstream fin("input.txt");
	fin >> b;
	fin.close();

	REQUIRE(b.search(10) != nullptr);
	REQUIRE(b.search(7) != nullptr);
	REQUIRE(b.search(3) != nullptr);
	REQUIRE(b.search(9) != nullptr);
	REQUIRE(b.search(8) != nullptr);
}

SCENARIO("Tree: operator <<", "[file and stream output]") {
	BinarySearchTree<size_t> b1{ 1, 2, 3, 4 }, b2(4);
	std::fstream f1("output.txt");
	f1 << b1;
	f1.close();
	std::ifstream f2("output.txt");
	f2 >> b2;
	f2.close();

	REQUIRE(b2.search(1) != nullptr);
	REQUIRE(b2.search(2) != nullptr);
	REQUIRE(b2.search(3) != nullptr);
	REQUIRE(b2.search(4) != nullptr);
}

SCENARIO("Tree: remove", "[remove]") {
	BinarySearchTree<size_t> b1{ 10, 7, 3, 8, 9, 12, 11, 15, 16, 17 };
	b1.remove(7);
	bool flag = false;
	try {
		b1.search(7);
	}
	catch (std::invalid_argument &e) {
		flag = true;
	}

	REQUIRE(flag);
}

SCENARIO("Tree: delete root without children", "[delete]") {
	BinarySearchTree<int> tree = { 8 };
	tree.remove(8);

	REQUIRE(tree.getNumber() == 0);
}

SCENARIO("Tree: delete root with one child", "[delete]") {
	BinarySearchTree<int> tree = { 8, 4, 3 };
	tree.remove(8);

	REQUIRE(((tree.search(4) != nullptr) && (tree.search(3) != nullptr)));
}

SCENARIO("Tree: delete root with children", "[delete]") {
	BinarySearchTree<int> tree1 = { 8, 4, 3, 10, 9, 13, 11, 12 };
	tree.remove(8);
	BinarySearchTree<int> tree2 = { 9, 4, 3, 10, 13, 11, 12 };
	REQUIRE(tree1 == tree2);
}

SCENARIO("Tree: delete non root with children", "[delete]") {
	BinarySearchTree<int> tree1 = { 8, 4, 3, 10, 9, 13, 11, 12 };
	tree.remove(10);
	BinarySearchTree<int> tree2 = { 8, 4, 3, 11, 9, 13, 12 };
	REQUIRE(tree1 == tree2);
}

SCENARIO("Tree: delete non root with one child", "[delete]") {
	BinarySearchTree<int> tree1 = { 8, 4, 3, 10, 9, 13, 11, 12 };
	BinarySearchTree<int> tree2 = { 8, 4, 3, 10, 9, 13, 12 };
	REQUIRE(tree1.remove(11));
	REQUIRE(tree1 == tree2);
}

SCENARIO("Tree: get root", "[get root]") {
	BinarySearchTree<size_t> b{ 1 };

	REQUIRE(b.getRoot() == 1);
}

SCENARIO("Tree: operator==", "[equal]") {
	BinarySearchTree<size_t> b1{ 1 }, b2{ 1 };

	REQUIRE(b1 == b2);
}

SCENARIO("Tree: create vector", "[vector]") {
	BinarySearchTree<size_t> b{ 1, 2, 3 };
	vector<size_t> tmp{ 1, 2, 3 };
	
	REQUIRE(tmp == b.createVector());
}
