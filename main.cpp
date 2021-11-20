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

  return 0;
}
