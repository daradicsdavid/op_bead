#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "create/create.h"
#include "print/print.h"
#include "model/order.h"
#include "update/update.h"
#include "file/file.h"
#include "select/select.h"
#include "delete/delete.h"
#include "filter/filter.h"
#include "menu/menu.h"
#include "read/read.h"

int main() {
    struct Order orders[50];
    int orderNumber = readFromFile(orders);
    int command;
    do {
        printMainMenu();
        if (!askMainMenu(&command)) {
            printf("Helytelen parancs!\n");
            continue;
        }
        if (command == 0) {
            createOrder(orders, &orderNumber);
        }
        if (command == 1) {
            if (orderNumber == 0) {
                printf("Jelenleg nincs rendelés a rendszerben!\n");
                continue;
            }
            int selectedOrder = selectOrder(orders, orderNumber);
            updateOrder(&orders[selectedOrder]);
        }
        if (command == 2) {
            if (orderNumber == 0) {
                printf("Jelenleg nincs rendelés a rendszerben!\n");
                continue;
            }
            int selectedOrder = selectOrder(orders, orderNumber);
            deleteOrder(orders, &orderNumber, selectedOrder);
        }
        if (command == 3) {
            if (orderNumber == 0) {
                printf("Jelenleg nincs rendelés a rendszerben!\n");
                continue;
            }
            printOrders(orders, orderNumber);
        }
        if (command == 4) {
            if (orderNumber == 0) {
                printf("Jelenleg nincs rendelés a rendszerben!\n");
                continue;
            }
            printFilterMenu();
            int filterCommand;
            if (!askFilterMenu(&filterCommand)) {
                printf("Helytelen parancs!\n");
                continue;
            }
            if (filterCommand == 0) {
                char filterWord[STR_LENGTH];
                printf("Adjon meg egy kulcsszót a kereséshez:");
                readString(filterWord);
                filterOrdersByName(orders, orderNumber, filterWord);
            }
            if (filterCommand == 1) {
                int filterRequirement;
                printf("Adjon meg egy teljesítmény értéket a kereséshez:");
                readInt(&filterRequirement);
                filterOrdersByPerformanceRequirement(orders, orderNumber, filterRequirement);
            }
        }
    } while (command != 5);
    writeToFile(orders, orderNumber);

}