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

int main() {
    struct Order orders[50];
    int orderNumber = readFromFile(orders);

    filterOrdersByPerformanceRequirement(orders, orderNumber, 32);
}