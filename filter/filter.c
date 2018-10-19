#include <string.h>
#include <stdio.h>
#import "../model/order.h"
#include "../print/print.h"
#include "../model/boolean.h"

int filterOrdersByName(struct Order orders[], int orderNumber, char *nameFilter) {
    boolean found = false;
    for (int i = 0; i < orderNumber; ++i) {
        if (strstr(orders[i].name, nameFilter) != NULL) {
            printOrder(orders[i]);
            found = true;
        }
    }
    if (!found) {
        printf("Nincs a követelménynek megfelelő találat.");
    }

}

int filterOrdersByPerformanceRequirement(struct Order orders[], int orderNumber, int performanceRequirementFilter) {
    boolean found = false;
    for (int i = 0; i < orderNumber; ++i) {
        if (orders[i].performanceRequirement == performanceRequirementFilter) {
            printOrder(orders[i]);
            found = true;
        }
    }
    if (!found) {
        printf("Nincs a követelménynek megfelelő találat.");
    }
}