#pragma once
#include<iostream>
//#include<stdio.h>
//#include<stack>
#include<iostream>
#include<string>

class BstNode
{
public:
    BstNode();
    ~BstNode();
    int data;
    BstNode* left;
    BstNode* right;
};




BstNode* GetNewNode(int data);
BstNode* Insert(BstNode* root, int data);
BstNode* Search(BstNode* root, int data);
int FindHeight(BstNode* root);






