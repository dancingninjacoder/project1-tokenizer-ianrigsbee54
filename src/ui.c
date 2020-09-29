#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 50 /*max characters for input*/
int main()
{
  char input[MAX]; /*input array for user input*/
  char **token; /*used for our tokenize method*/
  List *hist = init_history(); /*initialize history*/
  printf("Welcome to tokenizer\n");
  printf("here are your commands\n");
  printf("q : quits program\n");
  printf("h : prints history");
  printf("!x : brings up history at certain index x\n");
  
  while(*input != 'q'){/*while the users input isnt q for quit, run the loop*/
    printf("$ ");
    fgets(input, MAX, stdin);
    if(*input != '!' && *input != 'q'){
      printf("string entered is %s\n", input);
      token = tokenize(input); /*initialize our **token and fill the contents*/
      printf("tokenized string is\n");
      
      print_tokens(token); /*print our tokens*/
      printf("freeing tokens\n");
      free_tokens(token); /*free them*/
      printf("adding to history\n");
      add_history(hist, input); /*then add our input to our history list*/
    }
    if(*input == '!'){/*check if user inputed ! for history lookup*/
      int index = (int)(input[1]); 
      char *histStr = get_history(hist, index);/*get specific history at index*/
      printf("item at index %i%s\n",index, histStr);
    }
    if(*input == 'h'){/*if user inputs h itll simply print the history*/
      print_history(hist);
    }
    if(*input == 'q'){/*break out of loop to finish user input*/
      break;
    }
  
    
  }
  printf("All of your history strings were\n");
  print_history(hist); /*print user history*/
  printf("Now clearing history\n");
  free_history(hist);/*frees our history list before exiting program*/
  printf("Thank you for using tokenizer!\n");
  return 0;
  
}
