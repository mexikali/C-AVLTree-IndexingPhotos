#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"


int height(AVL tree){

    if(tree == NULL){
        return 0;}

return tree->height;
}


int max(int first,int second){

    if(first > second){
        return first;}

    else{
        return second;}

}



AVL turn_right(AVL tree) {

  AVL temp1,temp2;

  temp1 = tree ->left;
  temp2 = temp1 ->right;

  temp1->right = tree;
  tree->left = temp2;

  tree->height = max(height(tree->left), height(tree->right)) + 1;
  temp1->height = max(height(temp1->left), height(temp1->right)) + 1;

  return temp1;
}



AVL turn_left(AVL tree) {

  AVL temp1,temp2;

  temp1 = tree ->right;
  temp2 = temp1 ->left;

  temp1->left = tree;
  tree->right = temp2;

  tree->height = max(height(tree->left), height(tree->right)) + 1;
  temp1->height = max(height(temp1->left), height(temp1->right)) + 1;

  return temp1;
}



int balance(AVL tree) {

  if (tree == NULL)
    return 0;

return height(tree->left) - height(tree->right);
}



