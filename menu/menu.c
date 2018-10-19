#include <stdio.h>
#include "../read/read.h"

void printMainMenu() {
    printf("(0) Rendelés leadás\n");
    printf("(1) Rendelés módosítás\n");
    printf("(2) Rendelés törlés\n");
    printf("(3) Rendelés listázás\n");
    printf("(4) Rendelés keresés\n");
    printf("(5) Kilépés\n");
}

boolean askMainMenu(int *command) {
    readInt(command);
    if (*command < 0 || *command > 5) {
        return false;

    }
    return true;
}