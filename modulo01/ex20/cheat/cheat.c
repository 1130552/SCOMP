#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int random_number = rand() % 5 + 1;

    exit(random_number);
}