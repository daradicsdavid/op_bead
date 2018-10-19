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
            int selectedOrder = selectOrder(orders, orderNumber);
            updateOrder(&orders[selectedOrder]);
        }
        if (command == 2) {
            int selectedOrder = selectOrder(orders, orderNumber);
            deleteOrder(orders, &orderNumber, selectedOrder);
        }
        if (command == 3) {
            printOrders(orders, orderNumber);
        }
    } while (command != 5);
    writeToFile(orders, orderNumber);

}