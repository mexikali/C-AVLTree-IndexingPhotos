#ifndef AVLTREE_H
#define AVLTREE_H



struct Node_data {

      char name[20];
      char dimension[20];
      char size[20];
      char city[20];
      int year;

      struct Node_data *next;

};




struct Node_country {

      char country[20];
      struct Node_data *head;
      struct Node_data *tail;
      int num_of_photo;

      struct Node_country *right;
      struct Node_country *left;

      int height;

};
typedef struct Node_country *AVL;



int height(AVL tree);
int max(int first,int second);
AVL turn_right(AVL tree);
AVL turn_left(AVL tree);
int balance(AVL tree);


#endif
