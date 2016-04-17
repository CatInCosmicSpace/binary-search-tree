#include "stdafx.h"
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
	BinarySearchTree<size_t> b(5);
	fstream fin("input.txt");
	fin >> b;
	fin.close();

	REQUIRE(b.search(1) != nullptr);
	REQUIRE(b.search(2) != nullptr);
	REQUIRE(b.search(3) != nullptr);
	REQUIRE(b.search(4) != nullptr);
	REQUIRE(b.search(5) != nullptr);
}

SCENARIO("Tree: operator <<", "[file and stream output]") {
	BinarySearchTree<size_t> b1(5), b2(5);
	fstream fin("input.txt"), fout1("output.txt"), fout2("output.txt");
	fin >> b1;
	fout1 << b1;
	fout2 >> b2;
	REQUIRE(b2.search(1) != nullptr);
	REQUIRE(b2.search(2) != nullptr);
	REQUIRE(b2.search(3) != nullptr);
	REQUIRE(b2.search(4) != nullptr);
	REQUIRE(b2.search(5) != nullptr);
}

// EXCEPTION TIME
SCENARIO("Tree: empty", "[empty]") {
	BinarySearchTree<size_t> b;
	fstream fin("input.txt");
	bool flag = false;
	try {
		fin >> b;
	}
	catch (emptyTree e) {
		flag = true;
	}
	REQUIRE(flag);
}