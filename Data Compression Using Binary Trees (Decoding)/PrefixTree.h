#ifndef PREFIXTREE_H
#define PREFIXTREE_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class PrefixTree
{
    private:
        struct TreeNode
        {
            char character;
            TreeNode * left = NULL;
            TreeNode * right = NULL;
        };
        TreeNode* root = new TreeNode;
        char b = NULL;
        char c = NULL;
        int i = 0;

    public:

    PrefixTree(string value)
    {
        root->character = value[0];
        buildTree(value);
    }
    TreeNode* buildTree(string & value)
    {
        char b = value[i];

        if (b != '*')
        {
            cout << "leaf node: " << b << endl;
            TreeNode* currentNode = new TreeNode;
            currentNode->character = b;
            return currentNode;
        }
        else
        {
            cout<<"parent "<<b<<endl;
            TreeNode* currentNode = new TreeNode;
            currentNode->character = b;
            i++;
            currentNode->left = buildTree(value);
            i++;
            currentNode->right = buildTree(value);


            return currentNode;
        }

    }
    TreeNode * preorder()
    {

        preorderBuild(root);
    }

    TreeNode * preorderBuild(TreeNode* root)
    {
        c = root->character;
        if (c != '*')
        {
            cout << c << endl;
            return root;
        }
        else
        {
            cout << endl;
            cout<<"parent "<<c<<endl;
            root = preorderBuild(root->left);
            root = preorderBuild(root->right);
            return root;
        }


    }



     void printTree(TreeNode*node)
     {
         if (node)
         {
             cout << node->character <<endl;
             printTree(node->left);
             printTree(node->right);
         }
     }

};



#endif // PREFIXTREE_H
