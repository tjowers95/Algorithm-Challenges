/*This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, 
and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
    char* val;
    struct Node* left,* right;
};
struct Node* Node(char* val, struct Node* left, struct Node* right)
{
    struct Node* node = malloc(sizeof(*node));
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}
char* serialize(struct Node root, char* buffer)
{
    if (root.val == "root")
        strcpy(buffer, "root");
    else
        strcat(buffer,root.val);
    if (root.left == NULL)
        strcat(buffer, "(null l)");
    if (root.right == NULL)
        strcat(buffer, "(null r)");
    if (root.left != NULL)
        serialize(*(root.left),buffer);
    if (root.right != NULL)
        serialize(*(root.right),buffer);
    return buffer;
}

struct Node* deserialize(char* str)
{
    int cursor = 0, i = 0, t[128];
    if (*(str+cursor) == 'r' && *(str+cursor+1) == 'o')
    {
        struct Node* node = malloc(sizeof(*node));
        node = Node("root", NULL, NULL);
        cursor += 4;
    }
    
    while (*(str+cursor+i) != '(')
    {
        if (*(str+cursor) == 'l')
        {
            if (*(str+cursor+4) == '(' && *(str+cursor+15) == '(')
            {
                node.left()
            }
        }
            
        i++;
    }
}

int main(void)
{
    char* buffer = malloc(sizeof(char)*128);
    struct Node node = *Node("root",Node("left",Node("left.left",NULL,NULL),NULL),Node("right",NULL,NULL));
    char* str = serialize(node,buffer);
    printf(str);
    return 0;
}
