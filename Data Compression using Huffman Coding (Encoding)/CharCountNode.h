/*************************************************************
*
* Names: Joe Crumpton (jjc52)
*
* Course: CSE 2383
*
* File name: CharCountNode.h
*
* File Description:
* This file contains the class declaration and method definitions
* for the CharCountNode class. Feel free to use the class as is
* or make any changes you believe are needed. If you do change the
* code, add your name to the list above.
*
**************************************************************/

#ifndef CHAR_COUNT_NODE_H
#define CHAR_COUNT_NODE_H


/*************************************************************
This class was written to accompany the Huffman tree assignment
in Data Structures and Analysis of Algorithms.

Each instance of the class represents a character (and its
count, pointer to a left subtree, and pointer to a right
subtree) in a Huffman code tree.
**************************************************************/
class CharCountNode
{
private:
    char character;
    int count;
public:
    CharCountNode * left;
    CharCountNode * right;

    /**
       Default constructor.
    */
    CharCountNode()
    {
        character = '~';
        count = 0;
        left = right = NULL;
    }

    /**
       Parameter constructor.

       parameter c: the character to store in this node
       parameter n: the number of times that character c appears
       in the clear text message
    */
    CharCountNode(int n, char c)
    {
        character = c;
        count = n;
        left = right = NULL;
    }


    /**
       Destructor.
    */
    ~CharCountNode()
    {
        delete right;
        right = NULL;

        delete left;
        left = NULL;
    }

    /**
       Copy constructor.

       parameter rhs: The node that is copied by this method.
    */
    CharCountNode(const CharCountNode & rhs)
    {
        character = rhs.character;
        count = rhs.count;

        if (rhs.left == NULL)
            left = NULL;
        else
            left = new CharCountNode(*rhs.left);

        if (rhs.right == NULL)
            right = NULL;
        else
            right = new CharCountNode(*rhs.right);
    }

    /**
       Overloaded assignment method.

       parameter rhs: The node that provides new values for this node.
    */
    CharCountNode operator=(const CharCountNode & rhs)
    {
        character = rhs.character;
        count = rhs.count;

        if (rhs.left == NULL)
            left = NULL;
        else
            left = new CharCountNode(*rhs.left);

        if (rhs.right == NULL)
            right = NULL;
        else
            right = new CharCountNode(*rhs.right);

        return *this;
    }

    /**
       Returns the character stored in this node.
    */
    char getCharacter()
    {  // cout << character << endl;
        return character; }

    /**
       Returns the count stored in this node.
    */
    int getCount()
    { return count; }

    /**
       Overloaded <. Compares two nodes based on their counts.
    */
    bool operator<(const CharCountNode & rhs) const
    { return count < rhs.count; }

    /**
       Overloaded >. Compares two nodes based on their counts.
    */
    bool operator>(const CharCountNode & rhs) const
    { return count > rhs.count; }



};

#endif
