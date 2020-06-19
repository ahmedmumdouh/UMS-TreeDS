#pragma once
#include<iostream>
//#include<stdio.h>
//#include<stack>
//#include<iostream>
#include"BstNode.h"
//#include<string>
using namespace std;


student::student()
{
}


student::~student()
{
}

// Function to create a new Node in heap
student* GetNewNode(int id) {
    student* newNode = new student();
    newNode->id = id;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// To insert data in BST, returns address of root node
student* Insert(student* root, int id) {
    if (root == NULL) { // empty tree
        root = GetNewNode(id);
    }
    // if data to be inserted is lesser, insert in left subtree.
    else if (id <= root->id) {
        root->left = Insert(root->left, id);
    }
    // else, insert in right subtree.
    else {
        root->right = Insert(root->right, id);
    }
    return root;
}

//To search an element in BST, returns true if element is found
student* Search(student* root, int id) {
    if (root == NULL) {
        return nullptr;
    }
    else if (root->id == id) {
        return root;
    }
    else if (id <= root->id) {
        return Search(root->left, id);
    }
    else {
        return Search(root->right, id);
    }
}

/*

int FindHeight(BstNode* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);

    if (leftHeight>rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}


// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
    if (C >= '0' && C <= '9') return true;
    if (C >= 'a' && C <= 'z') return true;
    if (C >= 'A' && C <= 'Z') return true;
    return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
        return true;

    return false;
}

// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op)
{
    if (op == '$') return true;
    return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
    int weight = -1;
    switch (op)
    {
    case '+':
    case '-':
        weight = 1;
    case '*':
    case '/':
        weight = 2;
    case '$':
        weight = 3;
    }
    return weight;
}

// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if (op1Weight == op2Weight)
    {
        if (IsRightAssociative(op1)) return false;
        else return true;
    }
    return op1Weight > op2Weight ? true : false;
}




string InfixToPostfix(string expression)
{
    // Declaring a Stack from Standard template library in C++.
    stack<char> S;
    string postfix = ""; // Initialize postfix as empty string.
    for (int i = 0; i< expression.length(); i++) {

        // Scanning each character from left.
        // If character is a delimitter, move on.
        if (expression[i] == ' ' || expression[i] == ',') continue;

        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if (IsOperator(expression[i]))
        {
            while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i]))
            {
                postfix += S.top();
                S.pop();
            }
            S.push(expression[i]);
        }
        // Else if character is an operand
        else if (IsOperand(expression[i]))
        {
            postfix += expression[i];
        }

        else if (expression[i] == '(')
        {
            S.push(expression[i]);
        }

        else if (expression[i] == ')')
        {
            while (!S.empty() && S.top() != '(') {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }

    while (!S.empty()) {
        postfix += S.top();
        S.pop();
    }

    return postfix;
}*/
