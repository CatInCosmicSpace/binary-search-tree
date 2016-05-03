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
	BinarySearchTree<size_t> b1(10), b2(10);
	fstream fin("input.txt"), fout1("output.txt"), fout2("output.txt");
	fin >> b1;
	fout1 << b1;
	fout2 >> b2;
	fin.close();
	fout1.close();
	fout2.close();

	REQUIRE(b2.search(10) != nullptr);
	REQUIRE(b2.search(7) != nullptr);
	REQUIRE(b2.search(3) != nullptr);
	REQUIRE(b2.search(9) != nullptr);
	REQUIRE(b2.search(8) != nullptr);
}

SCENARIO("Tree: remove", "[remove]") {
	BinarySearchTree<size_t> b1(10);
	fstream fin1("input.txt"), fout("afterDel.txt");
	fin1 >> b1;
	fout << b1;
	b1.remove(7);
	bool flag = false;
	try {
		b1.search(7);
	}
	catch (std::invalid_argument &e) {
		flag = true;
	}
	fin1.close();
	fout.close();
	getchar();
	REQUIRE(flag);
}