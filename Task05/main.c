#include <stdio.h>
static int next_token(void){static int token=1000;return ++token;}
static int auto_token(void){int token=1000;return ++token;}
static int pointer_token(int *counter){return ++(*counter);}
int main(void){printf("static: %d %d %d\n",next_token(),next_token(),next_token());printf("auto : %d %d %d\n",auto_token(),auto_token(),auto_token());int veg=1000,nonveg=2000;printf("pointer counters: veg=%d,%d nonveg=%d,%d\n",pointer_token(&veg),pointer_token(&veg),pointer_token(&nonveg),pointer_token(&nonveg));for(register int i=1;i<=3;++i)printf("register loop: %d\n",i);return 0;}
