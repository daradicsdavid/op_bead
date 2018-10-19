#ifndef OP_BEAD_FILTER_H
#define OP_BEAD_FILTER_H

#import "../model/order.h"

int filterOrdersByName(struct Order orders[], int orderNumber, char *nameFilter);

int filterOrdersByPerformanceRequirement(struct Order orders[], int orderNumber, int performanceRequirementFilter);

#endif //OP_BEAD_FILTER_H
