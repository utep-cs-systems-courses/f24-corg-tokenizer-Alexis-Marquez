#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>
int space_char(char c){
  if(c=='\t' || c==' '){
    return 1;
      }else{
    return 0;
  }
}

int non_space_char(char c){
  if(c=='\0'){
    return 0;
  }
  return (space_char(c) == 0);
}

char *token_start(char *str){
  char *curr = str;
  while(space_char(*curr)&&*curr!='\0'){
    curr++;
  }
  return curr;
}
char *token_terminator(char *token){
  char *curr = token;
  while(non_space_char(*curr)){
    curr++;
  }
  return curr;
}

int count_tokens(char *str){
  char *curr = str;
  int count = 0;
  while(*curr!='\0'){
      curr = token_start(curr);
      curr = token_terminator(curr);
      count++;
    }
  return count;
}

char *copy_str(char *inStr, short len){
  char *strs;
  char *start = strs = malloc(len*sizeof(char*));
  int j = 0;
  while(*inStr!='\0'&& j<len){
    strs[j] = *inStr;
    inStr++;
    j++;
   }
  strs = '\0';
  return start;
}
char **tokenize(char* str){
  char** tokVec, **tvp;
  int numTokens = count_tokens(str);
  int size = (numTokens+1)*sizeof(char*);
  tvp = tokVec = malloc(size);
  char *start = token_start(str);
  while(*start!='\0'){
      char *end = token_terminator(start);
      char *tokCopy = copy_str(start, end-start);
      *tvp = tokCopy;
      tvp ++;
      start= token_start(end);
    }
  *tvp=0;
  return tokVec;
}
void print_tokens(char **tokens){
  for (int i = 0; tokens[i] != NULL; i++) {
    printf("%s\n", tokens[i]);
  }
}
void free_tokens(char **tokens){
  for (int i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }
  free(tokens);
}
