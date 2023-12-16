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

void updateProductionData(Production *target);

void getIdForChangeData(Production *head);

void getProduction(Production *prod);

Production* insertProduction(Production *head, int id, int day, int month, int year, const char *cultivar, char bundleType, int diameter, int gzBundleQuantity, float duration);

void findProductionByIdForDelete(Production *begin, int searchedId);

Production* findProductionById(Production *head, int idToSearch);

void getIdForDeleteData(Production *begin);

void printProductionDetails(Production *node);

void showProductionList(Production *begin);

void showReverseProductionList(Production *begin);

void showMenu();

void freeProductionList(Production *head);

Production* addSampleData(Production *head);

