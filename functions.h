#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data {
    int day;
    int month;
    int year;
} Data;

typedef struct grazingBundle {
    char cultivar[20];
    char bundleType;
    int diameter; // 80cm a 160cm e Altura de 150cm 
} GrazingBundle;

typedef struct production {
    int id;
    Data prodDate;
    GrazingBundle gzBundleType;
    int gzBundleQuantity;
    float duration;
    struct production *next;
    struct production *prev;
} Production;

Production* insertProduction(Production *head, int id, int day, int month, int year, const char *cultivar, char bundleType, int diameter, int gzBundleQuantity, float duration);

int getProduction();

int changeData();

int deleteData();

void printProductionList(Production *head);

int reverseListAll();

void showMenu();

