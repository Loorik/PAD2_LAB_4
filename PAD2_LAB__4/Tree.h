#pragma once
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <new>

#include "TreeNode.h"

// Tree class-template definition
template< typename NODETYPE > class Tree
{
public:
	Tree(); // constructor
	~Tree(); // destructor
	Tree(const Tree&) = delete; // no copies of Tree-objects allowed               
	const Tree& operator=(const Tree&) = delete; // no assignment allowed               

	void insertNode(const NODETYPE &);
	std::string inOrderTraversal() const;
	int getTotalWord() const { return totalWords; };
	int getUniqueWord() const { return uniqueWords; };
private:
	TreeNode< NODETYPE > * rootPtr;

	// utility functions
	void insertNodeHelper(TreeNode< NODETYPE > *&, const NODETYPE &);
	void inOrderHelper(TreeNode< NODETYPE > *, std::stringstream &) const;
	void destructorHelper(TreeNode< NODETYPE > *);
	int totalWords;
	int uniqueWords;
}; // end class Tree

// constructor
template< typename NODETYPE >
Tree< NODETYPE >::Tree()
{
	rootPtr = nullptr; // indicate tree is initially empty 
} // end Tree constructor

// destructor
template< typename NODETYPE >
Tree< NODETYPE >::~Tree()
{
	destructorHelper(rootPtr);
} // end Tree destructor

// insert node in Tree
template< typename NODETYPE >
void Tree< NODETYPE >::insertNode(const NODETYPE &value)
{
	insertNodeHelper(rootPtr, value);
	totalWords++;
} // end function insertNode

// utility function called by insertNode; receives a reference to a
// pointer so that the function can modify the pointer arguments's value
template< typename NODETYPE >
void Tree< NODETYPE >::insertNodeHelper(
	TreeNode< NODETYPE > *& ptr, const NODETYPE &value)
{
	// subtree is empty; create new TreeNode containing value
	if (ptr == nullptr) {
		ptr = new TreeNode< NODETYPE >(value);
		uniqueWords++;
	} // end if
	else { // subtree is not empty
	   // data to insert is less than data in current node
		if (value < ptr->data) {
			insertNodeHelper(ptr->leftPtr, value);
		} // end if
		else {
			// data to insert is greater than data in current node
			if (ptr->data < value)
				insertNodeHelper(ptr->rightPtr, value);
			else
			{// duplicate data value --> íncrement frequency, 
				ptr->frequency++;
				
			}
		}// end else
	} // end else
} // end function insertNodeHelper


// begin inorder traversal of Tree
template< typename NODETYPE >
std::string Tree< NODETYPE >::inOrderTraversal() const
{
	std::stringstream outStream;
	inOrderHelper(rootPtr, outStream);
	return outStream.str();
} // end function inOrderTraversal

// utility function to perform inorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::inOrderHelper(TreeNode< NODETYPE > *ptr, std::stringstream& outStream) const
{
	if (ptr != nullptr) {
		inOrderHelper(ptr->leftPtr, outStream);
		outStream << std::left << std::setfill('.') << std::setw(70) << ptr->data << ptr->frequency << '\n';
		inOrderHelper(ptr->rightPtr, outStream);
	} // end if
} // end function inOrderHelper


// utility function called by destructor for 
// deletion of subtrees using postorder traversal
template< class NODETYPE >
void Tree< NODETYPE >::destructorHelper(TreeNode< NODETYPE > * ptr)
{
	if (ptr != nullptr) {
		destructorHelper(ptr->leftPtr); // traversal order:
		destructorHelper(ptr->rightPtr); // leaves first!
		delete ptr; // delete leaf
	}
}

#endif