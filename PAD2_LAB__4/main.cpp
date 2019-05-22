#include <iostream>
#include <string>
#include <fstream>
#include "Tree.h"
#include "TreeNode.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	string word;
	ifstream inHeine("../Heine.txt", ios::in);
	if (!inHeine)
	{
		cerr << "File could not be opened";
		exit(EXIT_FAILURE);
	}

	Tree<string> t;

	while (inHeine >> word)
	{
		t.insertNode(word);
	}
	inHeine.close();

	ofstream outHeine("../Out.txt", ios::out);

	outHeine << t.inOrderTraversal();
	cout << "Anzahl der Knoten bzw. Wörter: " << t.getTotalWord()
		<< "\nAnzahl der doppelten Wörter: " << t.getUniqueWord();
}