#include "../model/order.h"
#include "../read/read.h"


void updateOrder(struct Order *order) {
    boolean updateNameAnswer = readYesNo("Szeretné megváltoztatni a nevét?");
    if (updateNameAnswer) {
        readName(order);
    }
    boolean updateEmailAnswer = readYesNo("Szeretné megváltoztatni az email címét?");
    if (updateEmailAnswer) {
        readEmail(order);
    }
    boolean updatePhoneAnswer = readYesNo("Szeretné megváltoztatni a telefonszámát?");
    if (updatePhoneAnswer) {
        readPhone(order);
    }
    boolean updatePerformanceRequirementAnswer = readYesNo(
            "Szeretné megváltoztatni a rendszer teljesítmény követelményét?");
    if (updatePerformanceRequirementAnswer) {
        readPerformanceRequirement(order);
    }
}
