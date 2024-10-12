#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>
#include "tokenizer.c"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "history.c"
#include "history.h"

int main(){
  List *list = init_history();
  char *str;
  while(1){
  str = malloc(300);
  printf("Enter string to tokenize, history to see previous strings, or q to exit: ");
  fgets(str, 300, stdin);
  str[strcspn(str,"\n")]=0;
  if(strcmp(str,"q")==0){
    printf("Exit\n");
    return 1;
  }
  if(*str == '!'){
    str++;
    str = get_history(list, atoi(str));
    if(str==NULL){
      printf("Invalid number, enter a valid index\n");
      continue;
    }
  }
  if(strcmp(str,"history")==0){
    printf("History: \n");
    print_history(list);
  }
  else{
  printf("You entered: %s\n", str);
  add_history(list, str);
  char **tokens = tokenize(str);
  print_tokens(tokens);
  free_tokens(tokens);
  }
  }
  free_history(list);
  free(str);
}
