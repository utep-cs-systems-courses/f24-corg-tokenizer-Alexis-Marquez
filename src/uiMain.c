#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>
#include "tokenizer.c"
#include <string.h>

int main(){
  while(1){
  char str[100];
  printf("Enter string: ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str,"\n")]=0;
  if(strcmp(str,"q")==0){
    printf("Exit\n");
    return 1;
  } 
  printf("You entered: %s\n", str);
  char **tokens = tokenize(str);
  print_tokens(tokens);
  free_tokens(tokens);
  }
}
