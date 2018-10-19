#include "../model/order.h"
#include "../read/read.h"


void createOrder(struct Order *order) {
    readName(order);
    readEmail(order);
    readPhone(order);
    readPerformanceRequirement(order);
    time(&order->time);
}
