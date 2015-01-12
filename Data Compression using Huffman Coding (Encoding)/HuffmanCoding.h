/********************************
*
* Name: Jennifer Jozefiak (jmj347)
*
*Course: CSE 2383
*
*File name: HuffmanCoding.h
*
* File Description:
* Program that reads in a string and creates a prefix code for it based off of Huffman's Code.
*
*********************************/
#ifndef HUFFMANCODING_H
#define HUFFMANCODING_H
#include "map"
#include "CharCountNode.h"
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <iterator>
#include <fstream>
#include <iostream>
#include <queue>
#include <functional>
#include <queue>
#include <stack>

using namespace std;

priority_queue< CharCountNode, vector<CharCountNode>, greater<CharCountNode> >pQueue;
priority_queue< CharCountNode, vector<CharCountNode>, greater<CharCountNode> >pQueue_second;

class HuffmanCoding
{
    private:
        map<char,int> mymap;
        map<char,int>::iterator iter;
        map<char,int>::iterator reSort;
        map<char,string> encoding;
        map<char,string>::iterator itEncode;
        map<char,string>::iterator itEncodeTwo;
        stack<char> printQueue;
        queue<string> binaryEncoding;
        queue<string> fileB;
        queue<char> prefixValue;
        string phrase_;
        int leftCount = 0;
        int rightCount = 0;
        int binary_count = 0;
        int i = 0;
    public:

        /** Construtcor, reads in the string **/
        HuffmanCoding(string phrase)
        {
            phrase_ = phrase;
            CountLetters(phrase);
        }

        /** Maps each letter in the string to the amount of times it occurs and pushes the resulting nodes onto a queue. **/
        void CountLetters(string phrase)
        {
            for (int i = 0; i < phrase.size(); i++){
                mymap[phrase[i]] = mymap[phrase[i]] + 1;
            }
            char character;
            int lowNum;
            int num;
            int totalChar = 0;
            iter = mymap.begin();
            reSort = mymap.begin();
            while(iter != mymap.end()){
                character = iter->first;
                num = iter->second;
                totalChar += num;
                lowNum = num;
                cout<<iter->first<< " => " << iter ->second <<endl;
                while(reSort!= mymap.end())
                {
                    if (num <= lowNum)
                    {
                        lowNum = num;
                    }
                    reSort++;
                }
                if (num == lowNum && character != '*')
                {
                    pQueue.push(CharCountNode(num,character));
                    character = '*';
                }
                iter++;
            }
            cout<< endl;
            cout << "Total Characters: " << totalChar << endl;
            MakeTree();
        }

            /** Goes through the queue, popping off two, adding their counts, and pushes it back onto the queue until their is one left. **/
            void MakeTree()
            {
                while(pQueue.size() != 1){
                    CharCountNode first = pQueue.top();
                    pQueue.pop();
                    CharCountNode second = pQueue.top();
                    pQueue.pop();
                    CharCountNode starNode(first.getCount() + second.getCount(), '*');
                   //cout << "StarNode Count " <<starNode.getCount() << "   StarNode Character: " << starNode.getCharacter()<< endl;
                    starNode.left = &first;
                    starNode.right = &second;
                    pQueue.push(starNode);
                }
                CharCountNode root = pQueue.top();
                cout<< endl;
                cout << "Prefix Code Tree: " << endl;
                BuildTree(root);
                cout << endl;
                cout << endl;
                cout << "Encodings:" << endl;
                Encodings(root,"");
                cout << endl;
                cout << endl;
                cout << "Encoded Message:" << endl;
                binaryString(phrase_);
                cout << endl;



            }

            /** Takes the queue and uncompresses it into a prefix code **/
            void BuildTree(CharCountNode node)
            {
                cout << node.getCharacter() << " " ;
                prefixValue.push(node.getCharacter());
                if (node.getCharacter() == '*')
                {
                    BuildTree(*node.left);
                    BuildTree(*node.right);
                }

            }

            /** Creates the binary code from the tree, prints it, and stores it into another map **/
            void Encodings(CharCountNode node, string binary_count)
            {
                char c = node.getCharacter();
                if (c!= '*')
                {
                    encoding[c] = binary_count;
                    cout << c << "     " << binary_count <<endl;
                }
                else
                {
                    Encodings(*node.left,binary_count + "0");
                    Encodings(*node.right,binary_count + "1");
                }
            }

            /** Prints the binary string based off of the previously made map **/
            void binaryString(string phrase)
            {
                for (int i = 0; i < phrase.length(); i ++){
                    char current = phrase[i];
                    itEncode = encoding.begin();
                    while (itEncode != encoding.end())
                    {
                        if (current == itEncode->first)
                        {
                            cout << itEncode->second ;
                            fileB.push(itEncode->second);
                        }
                    itEncode++;
                    }
                }
            }

            /** Writes to file **/
            void compress(string phrase)
            {
                string str = phrase;
                const char * x = str.c_str();
                ofstream myfile(x);
                if(myfile.is_open())
                {
                    while (!prefixValue.empty())
                    {
                        myfile << prefixValue.front();
                        prefixValue.pop();
                    }
                    myfile << endl;
                    while (!fileB.empty())
                    {
                        myfile << fileB.front();
                        fileB.pop();
                    }
                    myfile.close();
                }
                else
                {
                    cout << "Unable to open file" << endl;
                }
            }

};

#endif // HUFFMANCODING_H
