#pragma once
#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of class Tree
template< typename NODETYPE > class Tree;

// TreeNode class-template definition
template< typename NODETYPE >
class TreeNode
{
	friend class Tree< NODETYPE >;
public:
	// constructor
	TreeNode(const NODETYPE &d)
		: leftPtr(nullptr), // pointer to left subtree
		data(d), // tree node data
		rightPtr(nullptr) // pointer to right substree
	{ }
	// return copy of node's data
	NODETYPE getData() const { return data; }
private:
	TreeNode * leftPtr; // pointer to left subtree
	int frequency = 1;
	NODETYPE data;
	TreeNode * rightPtr; // pointer to right subtree
}; 

#endif