// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// BST class
// Creates a BST to store values
// Uses Node which holds the Data
// Uses templates to store any type of Data
// binarysearchtreee.cpp file is included at the bottom of the .h file
// binarysearchtreee.cpp is part of the template, cannot be compiled separately

#ifndef BST_HPP
#define BST_HPP

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

template<class T>
class BST {
    // display BST tree in a human-readable format
    friend ostream &operator<<(ostream &Out, const BST &Bst) {
        Bst.printSideways(Out, Bst.Root);
        Out << endl;
        Bst.printVertical(Out, Bst.Root);
        return Out;
    }

private:
    // Node for BST
    struct Node {
        T Data;
        struct Node *Left;
        struct Node *Right;
    };

    // refer to data type "struct Node" as Node
    using Node = struct Node;

    // root of the tree
    Node *Root{ nullptr };

    // height of a Node, nullptr is 0, Root is 1, static, no access to 'this'
    static int getHeight(const Node *N) {
        return 0;
    }

    /**
     * print tree sideways with root on left
                  6
              2
                  5
          0
                  4
              1
                  3
     */
    static ostream &printSideways(ostream &Out, const Node *Curr, int Level = 0) {
        const static char SP = ' ';
        const static int ReadabilitySpaces = 4;
        if (!Curr)
            return Out;
        printSideways(Out, Curr->Right, ++Level);
        Out << setfill(SP) << setw(Level * ReadabilitySpaces) << SP;
        Out << Curr->Data << endl;
        printSideways(Out, Curr->Left, Level);
        return Out;
    }

    static ostream &centeredPrint(ostream &Out, int Space,
        const string &Str, char FillChar = ' ') {
        auto StrL = static_cast<int>(Str.length());
        int Extra = (Space - StrL) / 2;
        if (Extra > 0) {
            Out << setfill(FillChar) << setw(Extra + StrL) << Str;
            Out << setfill(FillChar) << setw(Space - Extra - StrL) << FillChar;
        }
        else {
            Out << setfill(FillChar) << setw(Space) << Str;
        }
        return Out;
    }

    /**
     * print tree with the root at top
     *
        _____0______
     __1___      __2___
    3     4     5     6
     *
    **/
    static ostream &printTreeLevel(ostream &Out, queue<const Node *> &Q,
        int Width, int Depth, int MaxDepth) {
        const static char SP = ' ';
        const static char UND = '_';
        int Nodes = 0;
        int MaxN = pow(2, Depth - 1);
        int SpaceForEachItem = Width * pow(2, MaxDepth - 1) / MaxN; // NOLINT
        string
            Bigspace = string(static_cast<uint64_t>(SpaceForEachItem / 4), SP);
        while (Nodes++ < MaxN) {
            const Node *Tp = Q.front();
            Node *TpL = nullptr;
            Node *TpR = nullptr;
            Q.pop();
            string Label = "N";
            if (Tp) {
                stringstream Ss;
                Ss << Tp->Data;
                Label = Ss.str();
                TpL = Tp->Left;
                TpR = Tp->Right;
            }
            char Filler = Depth == MaxDepth ? SP : UND;
            if (Depth == MaxDepth) {
                centeredPrint(Out, SpaceForEachItem, Label, Filler);
            }
            else {
                Out << Bigspace;
                centeredPrint(Out, SpaceForEachItem / 2, Label, Filler);
                Out << Bigspace;
                Q.push(TpL);
                Q.push(TpR);
            }
        }
        Out << endl;
        return Out;
    }

    // helper function for displaying tree sideways, works recursively
    static ostream &printVertical(ostream &Out, Node *Curr) {
        const static int WIDTH = 6;  // must be even
        if (!Curr)
            return Out << "[__]";
        // figure out the maximum depth which determines how wide the tree is
        int MaxDepth = getHeight(Curr);
        queue<const Node *> Q;
        Q.push(Curr);
        for (int Depth = 1; Depth <= MaxDepth; ++Depth) {
            printTreeLevel(Out, Q, WIDTH, Depth, MaxDepth);
        }
        return Out;
    }

public:
    // constructor, empty tree
    BST() {

    }

    // constructor, tree with root
    explicit BST(const T &RootItem) {
        Root = new Node();
        Root->Data = RootItem;
    }

    // given an array of length n
    // create a tree to have all items in that array
    // with the minimum height (i.e. rebalance)
    // Assignment specification
    // NOLINTNEXTLINE
    BST(const T Arr[], int N) {
        Root = new Node();
        for (int I = 0; I < N; I++) {
            add(Arr[I]);
        }
    }

    // copy constructor
    BST(const BST<T> &Bst) {
        *this = Bst;
    }

    // destructor
    virtual ~BST() {
        clear();
    }

    // true if no nodes in BST
    bool isEmpty() const {
        if (Root == nullptr) {
            return true;
        }
        return false;
    }

    // 0 if empty, 1 if only root, otherwise
    // height of root is max height of subtrees + 1

    int getHeight()const {
        if (Root == nullptr) {//base case if the path hits a NULL (stem)
            return 0;
        }
        if (Root->Left == nullptr && Root->Right == nullptr) {
            return 1;
        }
        return getHeightHelper(Root);
    }

    int getHeightHelper(const Node* Top) const {
        if (Top == nullptr) {
            return 0;
        }
        int LeftDepth = getHeightHelper(Top->Left);//finding the deepest node on the left side of the node
        int RightDepth = getHeightHelper(Top->Right);//finding the deepest node on the right side of the node
        if (RightDepth > LeftDepth) {//compare the left and right sub branches
            return RightDepth + 1;
        }
        return LeftDepth + 1;//add one as it traverse the paths
    }

    // Number of nodes in BST
    int numberOfNodes() {
        if (Root == nullptr) {
            return 0;
        }
        if (Root->Left == nullptr && Root->Right == nullptr) {
            return 1;
        }
        return numberOfNodesHelper(Root);
    }

    int numberOfNodesHelper(Node* Leaf) {
        if (Leaf == nullptr) {
            return 0;
        }
        return 1 + numberOfNodesHelper(Leaf->Left) +
            numberOfNodesHelper(Leaf->Right);
    }

    // add a new item, return true if successful

    bool add(const T &Item) {
        auto Ptr = new Node;
        if (Ptr == nullptr) return false;            // out of memory
        Ptr->Data = Item;
        Ptr->Left = Ptr->Right = nullptr;

        if (isEmpty()) {
            Root = Ptr;
            return true;
        }
        auto Current = Root;
        bool Inserted = false;
        while (!Inserted) {
            if (Current->Data.compare(Ptr->Data) > 0) {
                if (Current->Left == nullptr) {              // insert left
                    Current->Left = Ptr;
                    Inserted = true;
                }
                Current = Current->Left;
            }
            else {
                if (Current->Right == nullptr) {
                    Current->Right = Ptr;
                    Inserted = true;
                }
                Current = Current->Right;
            }
        }
        return true;
    }
    Node* minValueNode(Node* Ptr)
    {
        Node* Current = Ptr;

        /* loop down to find the leftmost leaf */
        while (Current && Current->Left != nullptr)
            Current = Current->Left;

        return Current;
    }
    /* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
    bool remove(T deleteData) {
        deleteNode(Root, deleteData);
        return true;
    }

    Node* deleteNode(Node* Current, T Target)
    {
        // base case 
        if (Current == nullptr) return Current;

        // If the key to be deleted is smaller than the root's key, 
        // then it lies in left subtree 
        if (Target.compare(Current->Data) < 0)
            Current->Left = deleteNode(Current->Left, Target);

        // If the key to be deleted is greater than the root's key, 
        // then it lies in right subtree 
        else if (Target.compare(Current->Data) > 0)
            Current->Right = deleteNode(Current->Right, Target);

        // if key is same as root's key, then This is the node 
        // to be deleted 
        else
        {
            // node with only one child or no child 
            if (Current->Left == nullptr)
            {
                Node *Temp = Current->Right;
                delete Current;
                return Temp;
            }
            else if (Current->Right == nullptr)
            {
                Node *Temp = Current->Left;
                delete Current;
                return Temp;
            }

            // node with two children: Get the inorder successor (smallest 
            // in the right subtree) 
            Node* Temp = minValueNode(Current->Right);

            // Copy the inorder successor's content to this node 
            Current->Data = Temp->Data;

            // Delete the inorder successor 
            Current->Right = deleteNode(Current->Right, Temp->Data);
        }
        return Current;
    }






    // true if item is in BST
    bool contains(const T &Item) const {
        if (isEmpty()) {
            return false;
        }
        Node* Current = new Node();
        Current = Root;
        while (Current != nullptr) {
            if (Item.compare(Current->Data) < 0) {
                Current = Current->Left;
            }
            else if (Item.compare(Current->Data) > 0) {
                Current = Current->Right;
            }
            else if (Current->Data.compare(Item) == 0) {
                return true;
            }
        }
        return false;
    }

    // inorder traversal: left-root-right
    // takes a function that takes a single parameter of type T
    void inOrderTraverse(void Visit(const T &Item)) const {
        inOrderTraverseHelper(Visit, Root);
    }
    void inOrderTraverseHelper(void Visit(const T &Item), Node* NodePtr) const {
        if (NodePtr != nullptr) {
            inOrderTraverseHelper(Visit, NodePtr->Left);
            T TheItem = NodePtr->Data;
            Visit(TheItem);
            inOrderTraverseHelper(Visit, NodePtr->Right);
        }
    }


    // preorder traversal: root-left-right
    void preOrderTraverse(void Visit(const T &Item)) const {
        preOrderTraverseHelper(Visit, Root);
    }
    void preOrderTraverseHelper(void Visit(const T &Item), Node* NodePtr) const {
        if (NodePtr != nullptr) {
            T TheItem = NodePtr->Data;
            Visit(TheItem);
            preOrderTraverseHelper(Visit, NodePtr->Left);
            preOrderTraverseHelper(Visit, NodePtr->Right);
        }
    }

    // postorder traversal: left-right-root
    void postOrderTraverse(void Visit(const T &Item)) const {
        postOrderTraverseHelper(Visit, Root);
    }
    void postOrderTraverseHelper(void Visit(const T &Item), Node* NodePtr) const {
        if (NodePtr != nullptr) {
            postOrderTraverseHelper(Visit, NodePtr->Left);
            postOrderTraverseHelper(Visit, NodePtr->Right);
            T TheItem = NodePtr->Data;
            Visit(TheItem);
        }
    }
    // create dynamic array, copy all the items to the array
    // and then read the array to re-create this tree from scratch
    // so that resulting tree is balanced
    void rebalance() {
        // Store nodes of given BST in sorted order 
        if (Root == nullptr || (Root->Left == nullptr && Root->Right == nullptr)) {
            return;
        }
        T* Nodes;
        storeBSTNodes(Nodes);
        // Constructs BST from nodes[] 
        int N = numberOfNodes();
        Root = new Node();
        Root = rebalanceHelper(Nodes, 0, N - 1);
    }

    Node* rebalanceHelper(T* InOrderArr, int Start, int End)
    {
        // base case 
        if (Start > End) {
            return nullptr;
        }
        int Mid = (Start + End) / 2;
        auto Root = new Node();
        Root->Data = InOrderArr[Mid];
        Root->Left = rebalanceHelper(InOrderArr, Start, Mid - 1);
        Root->Right = rebalanceHelper(InOrderArr, Mid + 1, End);
        return Root;
    }

    void storeBSTNodes(T*& Nodes) {
        Nodes = new T[numberOfNodes()];
        stack<Node*> TempStack;
        Node* Current = Root;
        int Count = 0;
        while (Current != nullptr || TempStack.empty() == false)
        {
            while (Current != nullptr)
            {
                TempStack.push(Current);
                Current = Current->Left;
            }
            Current = TempStack.top();
            TempStack.pop();
            Nodes[Count] = Current->Data;
            Count++;
            Current = Current->Right;
        }
    }

    // delete all nodes in tree
    void clear() {
        clearHelper(Root);//delete each node in the tree
        Root = nullptr;
    }

    //---------------------------------------------------------------------------
    //Helper function for makeEmpty function
    //Delete every node in the tree recursivly
    //Also deletes pointer pointing at data, then the pointer itself
    void clearHelper(Node*& Ptr) {
        if (Ptr == nullptr) return;

        /* first delete both subtrees */
        clearHelper(Ptr->Left);
        clearHelper(Ptr->Right);

        delete Ptr;
    }
    //---------------------------------------------------------------------------
//Assignment operator
//Creates a deep copy of a binary tree
    BST& operator=(const BST<T> &Other) {
        if (this == &Other) {//checks for self assignment
            return *this;
        }
        clear();//empty out tree
        equalHelper(Root, Other.Root);//deep copy of tree (other)
        return *this;
    }

    //---------------------------------------------------------------------------
    // Helper function for operation overloading =
    //Will make a binary tree with same roots and subtrees

    void equalHelper(Node* &Original, const Node* Other) {

        if (Other == nullptr) {//base case for leafs
            Original = nullptr;
        }
        else {
            //must be preorder traversal
            auto Temp = new Node();
            Temp->Data = Other->Data;

            //add/set the node
            Original = new Node();
            Original->Data = Temp->Data;
            delete Temp;
            delete Original->Left;
            delete Original->Right;
            Original->Left = nullptr;
            Original->Right = nullptr;
            equalHelper(Original->Left, Other->Left);
            equalHelper(Original->Right, Other->Right);
        }
    }
    //---------------------------------------------------------------------------
//Equality
//Can only check between two binary trees
//Nothing gets changes in the two trees
    bool operator==(const BST<T> &Other) const {
        return isEqualHelper(Root, Other.Root);
    }

    //---------------------------------------------------------------------------
    //Helper function for operation overloading == and !=
    bool isEqualHelper(const Node* First, const Node *Second)const {
        //compares if both Nodes are nullptr
        if (First == nullptr && Second == nullptr) {
            return true;//base case for root and leaf nodes
        }
        //compare if both Node exist
        if (First != nullptr && Second != nullptr) {
            if (First->Data.compare(Second->Data) == 0) {//data must be equal
                //check the subtrees recursivly
                return ((isEqualHelper(First->Left, Second->Left) &&
                    (isEqualHelper(First->Right, Second->Right))));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    // not == to each other
    bool operator!=(const BST<T> &Other) const {
        return !(*this == Other);
    }
};

#endif  // BST_HPP