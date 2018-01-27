#include <iostream>

using namespace std;

/*
    In the bin-packing problem, we are given n metal objects, each weighing between
    zero and one kilogram. Our goal is to find the smallest number of bins that will
    hold the n objects, with each bin holding one kilogram at most.

    • The best-fit heuristic for bin packing is as follows. Consider the objects in the
    order in which they are given. For each object, place it into the partially filled
    bin with the smallest amount of extra room after the object is inserted.. If
    no such bin exists, start a new bin. Design an algorithm that implements the
    best-fit heuristic (taking as input the n weights w1, w2, ...,wn and outputting
    the number of bins used) in O(n log n) time.

    • Repeat the above using the worst-fit heuristic, where we put the next object in
    the partially filled bin with the largest amount of extra room after the object
    is inserted.
*/

// best-fit heuristic implementation

class RedBlackTree
{
    private:
        struct node
        {
            int weight;
            node* rightChild {nullptr};
            node* leftChild {nullptr};
            node* parent {nullptr}; // am using this so I can access the parents color
            bool isBlack {true}; // if it's not black, then it is red
        };
        node* treeHead = nullptr;

    public:
        RedBlackTree(int weight)
        {
            treeHead = new node;
            treeHead->weight = weight;
        }
        void addNode(int weight)
        {
            node* newNode = new node;
            newNode->weight = weight;
            node* trail = nullptr;
            node* temp = treeHead;
            while (temp != nullptr)
            {
                if (weight > treeHead->weight)
                {
                    trail = temp;
                    temp = treeHead->rightChild;
                }
                if (weight < treeHead->weight)
                {
                    trail = temp;
                    temp = treeHead->leftChild;
                }
            }
            if (weight > trail->weight)
            {
                trail->rightChild = newNode;
                newNode->parent = trail;
                newNode->leftChild = nullptr;
                newNode->rightChild = nullptr;
                if (trail->isBlack == true)
                {
                    newNode->isBlack = false;
                }
            }
            if (weight < trail->weight)
            {
                trail->leftChild = newNode;
                newNode->parent = trail;
                newNode->leftChild = nullptr;
                newNode->rightChild = nullptr;
                if (trail->isBlack == true)
                {
                    newNode->isBlack = false;
                }
            }

            // check if the left path and the right path
            // from some node to the nullptr tree leafs
            // contain the same amount of black nodes


            // what do I do if it is not the case?

        }
};

int main()
{
    int n;
    cout << "How many item weights will you enter?" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // input the weight into a binarySearchTree
        // check the binarySearchTree for the smallest number larger than n
        // calculate the new weight and find a new place for it in the tree...
        // will this take more than O(n log n)?
        // no, it won't; I have to implement a self-balancing binary search tree; I choose red-black
    }
    return 0;
}
