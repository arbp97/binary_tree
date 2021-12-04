#include "tree.h"
#include <vector>

using namespace std;

int main()
{
  Tree *tree = new Tree(3); // A (root)

  // DATASET:                B  C   D  E   F   G
  std::vector<int> dataset { 2, 1 };

  create(tree, dataset, 1);

  std::cout << "preOrder: "; preOrder(tree->root);

  getchar();

  std::cout << "inOrder: "; inOrder(tree->root);

  getchar();

  std::cout << "postOrder: "; postOrder(tree->root);
  /*
  int iNewNodeVal = 0;
  std::cout << "\nInsert new node: "; std::cin >> iNewNodeVal;

  insert(tree, iNewNodeVal, 1);

  inOrder(tree->root);

  int iSearchValue = 0;

  std::cout << "\nSearch for value: "; std::cin >> iSearchValue;

  switch (search(tree, iSearchValue))
  {
    case false: std::cout << "\nNot found" << '\n'; break;
    case true: std::cout << "\nFound" << '\n'; break;
  }
  */
  return 0;
}
