#include "execute.h" 

int main() {
    char *commands[] = {"ls", "pwd", "ps"};
    int argc = sizeof(commands) / sizeof(commands[0]);

    execute(argc, commands);

    return 0;
}