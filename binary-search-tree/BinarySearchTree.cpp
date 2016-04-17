#include "stdafx.h"
#include "BinarySearchTree.h"
#include <stdexcept>

using std::unique_ptr;
using std::move;
using std::ostream;
using std::istream;
using std::fstream;
using std::endl;

#ifndef BT_CPP
#define BT_CPP

template <typename T>	// WORKS
bool BinarySearchTree<T>::insert(const T &ref) {
	this->existed += 1;
	unique_ptr<node<T>> m_node(new node<T>(ref));

	if (root == nullptr) {
		root = move(m_node);
		return true;
	}
	else {
		node<T>* temp = root.get();
		node<T>* prev = root.get();

		while (temp != nullptr) {
			prev = temp;
			if (temp->data < ref) {
				temp = temp->right.get();
			}
			else {
				temp = temp->left.get();
			}
		}

		if (prev->data < ref) {
			prev->right = move(m_node);
		}
		else {
			prev->left = move(m_node);
		}
		return true;
	}
	return false;
}

template <typename T>	// WORKS
node<T> * BinarySearchTree<T>::search(const T &key) {
	node<T>* leaf = root.get();
	return search(key, leaf);
}

template <typename T>	// WORKS
node<T> * BinarySearchTree<T>::search(const T & key, node<T>* leaf) {
	if (leaf != nullptr) {
		if (key == leaf->data) {
			return leaf;
		}
		if (key < leaf->data) {
			return search(key, leaf->left.get());
		}
		else {
			return search(key, leaf->right.get());
		}
	}
	else {
		throw searchError();
	}
}

template <typename T>	// WORKS
size_t BinarySearchTree<T>::getCount() const {
	return this->count;
}

template <typename T>	// WORKS
bool BinarySearchTree<T>::print(const unique_ptr<node<T>> &m_node, ostream & os = std::cout) const {
	if (m_node == nullptr) {
		return true;
	}
	print(m_node->left, os);
	os << m_node->data << endl;
	print(m_node->right, os);
}

template <typename T>	// WORKS, вроде как
ostream & operator <<(ostream & os, const BinarySearchTree<T> & x) {
	if (x.root == nullptr) {
		throw emptyTree();
	}
	x.print(x.root, os);

	return os;
}

template <typename T>	// WORKS, вроде как
istream & operator >>(istream & input, BinarySearchTree<T> & x) {
	T temp;
	size_t steps = x.existed;
	for (size_t i = 0; i < steps; ++i) {
		try {
			if (input >> temp) {
				x.insert(temp);
			}
			else {
				throw invalidFile();
			}
		}
		catch (...) {
			throw invalidFile();
		}
	}
	return input;
}

template <typename T>	// MAYBE
fstream & operator <<(fstream &file, BinarySearchTree<T> & x) {
	if (x.root == nullptr) {
		throw emptyTree();
	}
	x.print(x.root, file);

	return file;
}

template <typename T>	// WORKS, вроде как
fstream & operator >>(fstream &file, BinarySearchTree<T> & x) {
	T temp;
	for (size_t i = 0; i < x.existed; ++i) {
		try {
			if (file >> temp) {
				x.insert(temp);
			}
			else {
				throw invalidFile();
			}
		}
		catch (...) {
			throw invalidFile();
		}
	}
	return file;
}
#endif