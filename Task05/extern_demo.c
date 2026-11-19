#include <stdio.h>
#include "token_shared.h"
int main(void) {
    int first = next_shared_token();
    int second = next_shared_token();
    int third = next_shared_token();
    printf("extern: %d %d %d\n", first, second, third);
    return 0;
}
