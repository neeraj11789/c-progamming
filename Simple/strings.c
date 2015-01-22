#include<stdio.h>
#include<string.h>

#define MAX_STRING_LEN 255
#define MAX_TOKS 100
#define DELIMITERS " \t"

void stringPrint() {
  
  /* strings are array of characters 
   * terminated by the NULL character
   * which is different from '0' */
  
  char S[MAX_STRING_LEN];
  int l, i;
  
  S[0] = 'a';
  S[1] = 'b';
  S[2] = 'c';
  S[3] = 'd';
  S[4] = 'e';
  S[5] = 'g';
  S[6] = '0';
  S[7] = 0;

  l = strlen(S);

  printf("S:\t%s\n",S);
  printf("length:\t%d\n",l);
  
  /* print characters in S */
  
  printf("forward\n");
  for (i = 0; i < l; ++i) 
    printf("A[%d] = %c\n",i,S[i]);
  
  /* print characters in S backwards */
  
  printf("\nbackward\n");
  for (i = l-1; i >= 0; --i) 
    printf("A[%d] = %c\n",i,S[i]);
}

int stringIO() {
  
  /* strings can be read using scanf with %s
   * string.h contains many useful functions
   * for working with strings:
   *   strcmp for string comparisons
   *   strcpy to copy strings
   *   ...
   *
   * Check what happens if your input contains
   * spaces, tabs, etc
   *
   */

  char S1[MAX_STRING_LEN];
  char S2[MAX_STRING_LEN];
  
  int i, l;

  printf("String:\t");
  scanf("%s",S1);

  /* we need to copy all the characters, and
   * the final NULL character!
   */

  l = strlen(S1);
  /* rather than writing this loop
     we could also write strcpy(S2,S1) */

  for (i = 0; i < l+1; ++i)
    S2[i] = S1[i];


  /* change original S1 */
  S1[0] = S1[1] = S1[2] = '*';
  S1[3] = 0;

  /*These both end the string*/
  S1[1] = '\0';
  S2[2] = 0;

  /* print both strings */
  printf("S1:\t%s\n",S1);
  printf("S2:\t%s\n",S2);

}


void StringComparision() {
  
  /* What is the result of the following
   * for different strings S1, S2?
   */

  char S1[MAX_STRING_LEN];
  char S2[MAX_STRING_LEN];
  
  int i, l, res;

  printf("String1:\t");
  scanf("%s",S1);

  printf("String2:\t");
  scanf("%s",S2);

  res = strcmp(S1,S2);

  printf("strcmp(%s,%s) = %d\n",S1,S2,res);

}

void stringCopy() {
  
  /* Warning: Strings aren't regular variables
   * You've to be careful with string comparison
   * and assignments.
   */

  char* S1 = "AAAAAAAAAA";
  char* S2 = "BBBBBBBBBB";
  
  int i, l;

  /* assign S1 to S2 */
  S2 = S1;

  /* change S1 */
  // S1[0] = S1[1] = S1[2] = '*';
  // S1[3] = 0;

  /* print both strings */
  printf("S1:\t%s\n",S1);
  printf("S2:\t%s\n",S2);

}

void stringCmp() {
  
  /* Warning: Strings aren't regular variables
   * You've to be careful with string comparison
   * and assignments.
   */

  char* S1 = "AAAAAAAAAA";
  char* S2 = "BBBBBBBBBB";
  
  int cmp1, cmp2, cmp3, cmp4;
  
  cmp1 = (S1 == S2);
  cmp2 = strcmp(S1,S2);
  
  printf("S1:\t%s\n",S1);
  printf("S2:\t%s\n",S2);
  printf("S1 == S2:\t%d\n",cmp1);
  printf("strcmp(S1,S2):\t%d\n",cmp2);

  S2 = S1;
  cmp3 = (S1 == S2);
  cmp4 = strcmp(S1,S2);
  printf("\nafter assignment\n");
  printf("S1:\t%s\n",S1);
  printf("S2:\t%s\n",S2);
  printf("S1 == S2:\t%d\n",cmp3);
  printf("strcmp(S1,S2):\t%d\n",cmp4);
}

#include<string.h>
#include<stdio.h>

#define MAX_STRING_LENGTH 80

void stringConcat() {
  /* strcat is another useful command:
   * it appends a copy of a second string
   */

  char S1[MAX_STRING_LENGTH];
  char S2[MAX_STRING_LENGTH];

  strcat(S1,S2);

  printf("S1:\t");
  scanf("%s",S1);

  printf("S2:\t");
  scanf("%s",S2);

  strcat(S1,S2);

  printf("\nafter strcat(S1,S2)\n");
  printf("S1:\t%s\n",S1);
  printf("S2:\t%s\n",S2);

}


int scanLine() {

  /* this example is useful for your homework:
   * it read an input line and extract the first
   * four words.
   *
   * What happens if you enter more than four words?
   * What if there are less than four words?
   *
   * This example is useful for the shell assignment.
   * It might be a reasonable assumption that each
   * command has less than a fixed number of paramters.
   * However, for a real shell you don't want to make 
   * this restriction.
   */

  char S[MAX_STRING_LENGTH];
  char A0[MAX_STRING_LENGTH];
  char A1[MAX_STRING_LENGTH];
  char A2[MAX_STRING_LENGTH];
  char A3[MAX_STRING_LENGTH];

  int n;
  
  /* gets reads an entire line from the input */
  gets(S);
  
  /* read four strings from array of character S */
  n = sscanf(S,"%s %s %s %s",A0,A1,A2,A3);
  
  printf("strings read:\t%d\n",n);
  printf("A0:\t%s\n",A0);
  printf("A1:\t%s\n",A1);
  printf("A2:\t%s\n",A2);
  printf("A3:\t%s\n",A3);

}

int parseString(char* line, char*** argv) {

  char* buffer;
  int argc;

  buffer = (char*) malloc(strlen(line) * sizeof(char));
  strcpy(buffer,line);
  (*argv) = (char**) malloc(MAX_TOKS * sizeof(char**));

  argc = 0;  
  (*argv)[argc++] = strtok(buffer, DELIMITERS);
  while ((((*argv)[argc] = strtok(NULL, DELIMITERS)) != NULL) &&
   (argc < MAX_TOKS)) ++argc;

  return argc;
}



int parsing() {

  char S[MAX_STRING_LENGTH];

  char **A;
  int  n,i;

  /* gets reads an entire line from the input */
  gets(S);

  /* splits the input line into separate words */
  n = parseString(S, &A);  

  printf("strings read:\t%d\n",n);
  
  for (i = 0; i < n; ++i)
    printf("A[%d] = %s\n",i,A[i]);

}


int main(){
  // stringPrint();
  // stringIO();
  // StringComparision();
  // stringCopy();
  // stringCmp();
  // stringConcat();
  // scanLine();
  parsing();
}