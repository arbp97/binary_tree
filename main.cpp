#include "tree.h"
#include <vector>

using namespace std;

int main()
{
  Tree* tree = new Tree(15); // A (root)

  // DATASET:                B  C   D  E   F   G
  std::vector<int> dataset { 3, 36, 2, 12, 28, 39 };

  create(tree, dataset);

  // DATASET RESULT: 15 - 3 - 2 - 12 - 36 - 28 - 39
  std::cout << "preOrder: "; preOrder(tree->root);

  getchar();

  // DATASET RESULT: 2 - 3 - 12 - 15 - 28 - 36 - 39
  std::cout << "inOrder: "; inOrder(tree->root);

  getchar();

  // DATASET RESULT: 2 - 12 - 3 - 28 - 39 - 36 - 15
  std::cout << "postOrder: "; postOrder(tree->root);

  int iNewNodeVal = 0;
  std::cout << "\nInsert new node: "; std::cin >> iNewNodeVal;

  insert(tree, iNewNodeVal);

  inOrder(tree->root);

  int iSearchValue = 0;

  std::cout << "\nSearch for value: "; std::cin >> iSearchValue;

  switch (search(tree, iSearchValue))
  {
    case false: std::cout << "\nNot found" << '\n'; break;
    case true: std::cout << "\nFound" << '\n'; break;
  }

  return 0;
}
