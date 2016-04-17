#pragma once
#include <cstdlib>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <stdexcept>

using std::exception;
using std::unique_ptr;
using std::ostream;
using std::istream;
using std::fstream;

#ifndef BT_H
#define BT_H

class emptyTree : public exception {};
class ivalidKey : public exception {};
class invalidFile : public exception {};
class searchError : public exception {};


template <typename T>
class BinarySearchTree;

template <typename T>
ostream & operator<<(ostream & output, const BinarySearchTree<T> &);

template <typename T>
istream & operator>>(istream & input, BinarySearchTree<T> &);

template <typename T>
fstream & operator<<(fstream & file, BinarySearchTree<T> &);

template <typename T>
fstream & operator>>(fstream & file, BinarySearchTree<T> &);

template <typename T>
struct node {
	typedef unique_ptr<node<T>> ptrNode;

	T		data;
	ptrNode		left;
	ptrNode		right;
	node(const T & value) : data(value), left(nullptr), right(nullptr) {};
};

template <typename T>
class BinarySearchTree {
private:
	typedef		unique_ptr<node<T>> ptrNode;
	ptrNode		root;
	size_t		count;
	size_t		existed;

	bool		print(const unique_ptr<node<T>>&, ostream &);
	node<T> *	search(const T &key, node<T>* leaf);
public:
	BinarySearchTree() : root(nullptr), count(0), existed(0) {};		// TESTED
	BinarySearchTree(size_t k) : root(nullptr), count(k), existed(0) {};	// TESTED

	bool		insert(const T &node);							// TESTED
	node<T> *	search(const T &key);							// TESTED
	size_t		getCount() const;							// TESTED
	size_t		getNumber() const;							// TESTED

	friend		ostream & operator<< <>(ostream &output, const BinarySearchTree &);	// TESTED
	friend		istream & operator>> <>(istream &input, BinarySearchTree &);		// TESTED
	friend		fstream & operator<< <>(fstream &file, BinarySearchTree<T> &);		// TESTED
	friend		fstream & operator>> <>(fstream &file, BinarySearchTree<T> &);		// TESTED
};

#include "BinarySearchTree.cpp"

#endif
