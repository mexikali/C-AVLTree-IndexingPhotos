                                    /*2315539 Ömer Faruk Sezen*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"avltree.h"
#include"avltree.c"
#include "stack.h"
#include "stack.c"



/*Struct Node_country node, the main node of the AVL tree. If there are other photos in the same country,
their information is stored in the Node_data node included in the Node_country node.*/
AVL insertPhoto(AVL tree, char name[20], char dimension[20], char size[20], char city[20],char country[20], int year) {

  if (tree == NULL){

          AVL new_node = (struct Node_country *)malloc(sizeof(struct Node_country));

          new_node->head = (struct Node_data *) malloc(sizeof(struct Node_data));

                          if ( new_node->head == NULL)
                                    printf("Out of memory!\n");

                          else{

                                  strcpy(new_node->head->name,name);
                                  strcpy(new_node->head->dimension,dimension);
                                  strcpy(new_node->head->size,size);
                                  strcpy(new_node->country,country);
                                  strcpy(new_node->head->city,city);
                                  new_node->head->year = year;
                                  new_node->num_of_photo = 1;

                                  new_node->tail = new_node->head;
                                  new_node->head->next = NULL;
                                  new_node->left = NULL;
                                  new_node->right = NULL;
                                  new_node->height = 1;

                                  return (new_node);}       }



  else if (strcmp(country,tree->country) == 0){

          struct Node_data *temp1,*temp2;

          temp1 = tree->tail->next;
          temp2 = tree->tail;

          temp1 = (struct Node_data *) malloc(sizeof(struct Node_data));

                          if ( temp1 == NULL)
                                    printf("Out of memory!\n");

                          else{

                                  strcpy(temp1->name,name);
                                  strcpy(temp1->dimension,dimension);
                                  strcpy(temp1->size,size);
                                  strcpy(tree->country,country);
                                  strcpy(temp1->city,city);
                                  temp1->year = year;
                                  tree->num_of_photo ++;

                                  temp2 ->next = temp1;
                                  tree->tail = temp1;
                                  tree->tail->next = NULL;

                                        if( tree->num_of_photo == 2){
                                            tree->head->next = tree->tail;}


                                  return (tree);}       }



   if ( strcmp(country,tree->country) == -1 ){
        tree->left = insertPhoto(tree->left,name,dimension,size,city,country,year);}

   else if ( strcmp(country,tree->country) == 1 ){
        tree->right = insertPhoto(tree->right,name,dimension,size,city,country,year);}

  else{
        return tree;}


  tree->height = 1 + max(height(tree->left),height(tree->right));


  int balance_tree;

        balance_tree = balance(tree);


          if (balance_tree > 1 && strcmp(country,tree->left->country) == -1)
            return turn_right(tree);

          if (balance_tree < -1 && (strcmp(country,tree->right->country) == 1) )
            return turn_left(tree);

          if (balance_tree> 1 && (strcmp(country,tree->left->country) == 1) ) {
            tree->left = turn_left(tree->left);
            return turn_right(tree);
          }

          if (balance_tree < -1 && (strcmp(country,tree->right->country) == -1) ) {
            tree->right = turn_right(tree->right);
            return turn_left(tree);
          }

return tree;
}




AVL readData(char file_name[20]){

    FILE *file;

    AVL tree;

    tree = NULL;

    int year;
    char name[20],dimension[20],size[20],city[20],country[20];


    file = fopen(file_name,"r");

    if( file == NULL){
        printf("%s file not found...",file_name);}

    else{

        while (!(feof(file))){

                fscanf(file,"%[^,],%[^,],%[^,],%[^,],%[^,],%d\n",&name,&dimension,&size,&city,&country,&year);

                 tree = insertPhoto(tree,name,dimension,size,city,country,year);   }
        }

fclose(file);

return tree;

}


/*This function takes the AVL tree and x value as input. If x is 0, it prints the whole tree.
If it is different from zero,
it prints photos with the same year as its value.*/
void displayIndex(AVL tree,int x){

 int i;

  if (tree != NULL && x == 0) {

    displayIndex(tree->left,x);

                  struct Node_data *temp;

                  temp = tree ->head;

                  for ( i=0; i<tree->num_of_photo;i++){
                    printf("%s,%s,%s,%s,%s,%d\n",temp ->name,temp ->dimension,temp ->size,temp ->city,tree ->country,temp ->year);
                    temp = temp ->next;
                    }

    displayIndex(tree->right,x);
  }



  else if (tree != NULL && x != 0) {

    displayIndex(tree->left,x);

                  struct Node_data *temp;

                  temp = tree ->head;

                  for ( i=0; i<tree->num_of_photo;i++){

                            if(temp->year == x){

                                    printf("%s,%s,%s,%s,%s,%d\n",temp ->name,temp ->dimension,temp ->size,temp ->city,tree ->country,temp ->year);}

                    temp = temp ->next;
                    }

    displayIndex(tree->right,x);
  }


}


/*This function takes the AVL tree as input. Struct checks Node_country nodes one by one and
 returns the node with the highest num_of_photo value.*/
AVL  popularCountry(AVL tree){

    AVL popular,popular_left,popular_right;

    popular = (struct Node_country *)malloc(sizeof(struct Node_country));
    popular_left = (struct Node_country *)malloc(sizeof(struct Node_country));
    popular_right = (struct Node_country *)malloc(sizeof(struct Node_country));

    popular ->num_of_photo= 0;
    popular_left ->num_of_photo= 0;
    popular_right ->num_of_photo= 0;

    if( tree != NULL){

     popular_left = popularCountry(tree ->left);
     popular_right = popularCountry(tree ->right);

            if( tree->num_of_photo > popular->num_of_photo){
                popular = tree;
                popular->left = NULL;
                popular->right = NULL;
            }

              if( popular_left ->num_of_photo > popular->num_of_photo){
                    popular = popular_left;}

              if( popular_right ->num_of_photo > popular->num_of_photo){
                    popular = popular_right;}
    return popular;
    }

/*Complexity of this function is O (n), since it is a recursive function and does not perform complex operations.
We can use queue ADT of stack ADT, but the complexity of the function does not change.*/
return popular;
}




/*I wrote this function to facilitate the popularYear function. The AVL takes the tree and the stack and
pushes all the years that the pictures into the stack. It returns the stack.*/
stack year_stack(AVL tree, stack s){


    if (tree != NULL)


        {

             s = year_stack(tree->right,s);
             s = year_stack(tree->left,s);

                          struct Node_data *temp;

                          temp = tree ->head;
                          int i;

                          for ( i=0; i<tree->num_of_photo;i++){
                            s = push(temp->year,s);
                            temp = temp ->next;
                            }

        }


return s;
}



/*This function takes the AVL tree and defines a stack.
Fills the stack by calling the year_stack function.
Next, it defines a new stack and reduces the years in the first stack to one and adds the number of photos from those years to the stack.
He then puts the most photographed year in an integer array.
Finally, it prints the photos of the most photographed year by calling the displayIndex function.*/
void popularYear(AVL tree){

    int year_max[2];

    stack s,s_max_year,max;


    s = NULL;
    s_max_year = NULL;

    s = year_stack(tree,s);

    s_max_year = push(s->val,s_max_year);
    s_max_year->size_of_stack = 1;
    s_max_year->next = NULL;
    s = pop(s);

   while (s != NULL){

        int condition = 0;

        stack s_max_year_temp;
        s_max_year_temp = s_max_year;


            while (s_max_year_temp != NULL){

                    if( s_max_year_temp->val == s->val ){

                        s_max_year_temp->size_of_stack++;

                        s = pop(s);

                        condition = 1;}


                s_max_year_temp = s_max_year_temp->next;   }


            if (condition == 0){

                s_max_year = push(s->val,s_max_year);
                s_max_year->size_of_stack = 1;

                s = pop(s); }
}

    year_max[0] = s_max_year->val;
    year_max[1] = s_max_year->size_of_stack;
    s_max_year = pop(s_max_year);

    while (s_max_year != NULL){

        if( s_max_year->size_of_stack > year_max[1]){

                year_max[0] = s_max_year->val;
                year_max[1] = s_max_year->size_of_stack;    }

        s_max_year = pop(s_max_year);   }

/*The complexity of this function is O (n ^ 2) because there are two nested loops and
there is no other operation more complex than O (n ^ 2).
We can queue ADT, but it does not change the complexity in this function. */
displayIndex(tree,year_max[0]);
}



int main(int argc,char ** argv){

				if(argc == 1){

					printf("Please enter  command line argument and restart...");

					return 0;
				}

    printf(">>>Welcome to Photo Indexing<<<");

    int choice;

    do{
    printf("\n-----------------------------------------------------------------------------\n");
    printf("-Menu-\n1. Display the full index of photos\n2. Display the photos of popular country\n3. Display the photos of popular year\n4. Exit\n\n");

    printf("Option: ");
    scanf("%d",&choice);

        AVL tree,popular;
        tree = readData(argv[1]);


            if ( choice == 1){

                printf("Photo Index:\n");
                displayIndex(tree,0); }


            else if  ( choice == 2){

                     popular = popularCountry(tree);
                     printf("Photos of popular country:\n");
                     displayIndex(popular,0);     }


            else if  ( choice == 3){

                     printf("Photos of popular year:\n");
                     popularYear(tree);     }


            else if   ( choice == 4){

                        return 0;   }


           else{

                    printf("\nPlease choose one of the available options...");
           }



    }while(choice != 4);

return 0;

}
