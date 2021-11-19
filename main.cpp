#include "tree.h"
#include <vector>

using namespace std;

int main()
{
    Tree* tree = new Tree(15);
    std::vector<int> dataset { 3, 36, 2, 12, 28, 39 };
    
    create(tree, dataset);
    
    preOrder(tree->root);
    
    return 0;
}
