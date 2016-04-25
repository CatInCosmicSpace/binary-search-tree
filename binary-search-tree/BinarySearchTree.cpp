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
bool BinarySearchTree<T>::remove(const T &key) {
	return remove(key, this->root);
}

template<typename T>	// WORKS
bool BinarySearchTree<T>::remove(const T &key, unique_ptr<node<T>> &leaf) {
	if (leaf != nullptr) {
		if (key == leaf->data) {
			leaf.reset();

			return true;
		}
		if (key < leaf->data) {
			return remove(key, leaf->left);
		}
		else {
			return remove(key, leaf->right);
		}
	}
	else {
		throw std::logic_error("Remove error");
	}
	return true;
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
		throw std::invalid_argument("Wrong index");
	}
}

template <typename T>	// WORKS
size_t BinarySearchTree<T>::getCount() const {
	return this->count;
}

template<typename T>	// WORKS
size_t BinarySearchTree<T>::getNumber() const {
	return this->existed;
}

template <typename T>	// WORKS
bool BinarySearchTree<T>::print(const unique_ptr<node<T>> &m_node, ostream & os = std::cout) {
	node<T>* tmp = m_node.get();

	if (m_node.get() == nullptr) {
		return true;
	}
	if (tmp->left.get() != nullptr) {
		print(tmp->left, os);
	}
	os << m_node->data << endl;
	if (tmp->right.get()) {
		print(tmp->right, os);
	}
}

template <typename T>	// WORKS
ostream & operator <<(ostream & os, BinarySearchTree<T> & x) {
	if (x.root == nullptr) {
		throw std::logic_error("Empty tree");
	}
	x.print(x.root, os);

	return os;
}

template <typename T>	// WORKS
istream & operator >>(istream & input, BinarySearchTree<T> & x) {
	T temp;
	if (x.count == 0) {
		throw std::logic_error("Empty tree");
	}
	else {
		for (size_t i = 0; i < x.count; ++i) {
			if (input >> temp) {
				x.insert(temp);
			}
			else {
				throw std::logic_error("Error in input stream");
			}
		}
		return input;
	}
}

template <typename T>	//WORKS
fstream & operator <<(fstream &file, BinarySearchTree<T> & x) {
	if (x.count == 0) {
		throw std::logic_error("Empty tree");
	}
	x.print(x.root, file);

	return file;
}

template <typename T>	// WORKS
fstream & operator >>(fstream &file, BinarySearchTree<T> & x) {
	T temp;
	if (x.count == 0) {
		throw std::logic_error("Empty tree");
	}
	else {
		for (size_t i = 0; i < x.count; ++i) {
			if (file >> temp) {
				x.insert(temp);
			}
			else {
				throw std::logic_error("Error in input stream");
			}
		}
		return file;
	}
}
#endif
