#include <stdio.h>
#include <string.h>
#include "../model/order.h"
#include "../model/boolean.h"


int readString(char *str) {
    fgets(str, STR_LENGTH, stdin);
    str[strcspn(str, "\n")] = 0;
}

void readInt(int *integer) {
    scanf("%d", integer);
    getchar();
}

boolean readYesNo(char *question) {
    printf(question);
    printf("No(0),Yes(1)\n");
    int answer;
    scanf("%d", &answer);
    getchar();
    return answer == 0 ? false : true;
}

void readName(struct Order *order) {
    printf("Kérem adja meg a nevét: ");
    char name[STR_LENGTH];
    readString(name);

    strcpy(order->name, name);
}

void readEmail(struct Order *order) {
    printf("Kérem adja meg az email címét: ");
    char email[STR_LENGTH];
    readString(email);
    strcpy(order->email, email);
}

void readPhone(struct Order *order) {
    printf("Kérem adja meg a telefon számát: ");
    char phone[STR_LENGTH];
    readString(phone);
    strcpy(order->phone, phone);
}

void readPerformanceRequirement(struct Order *order) {
    printf("Kérem adja meg mekkora teljesítményű rendszert szeretne: ");
    int performanceRequirement;
    readInt(&performanceRequirement);
    order->performanceRequirement = performanceRequirement;
}



