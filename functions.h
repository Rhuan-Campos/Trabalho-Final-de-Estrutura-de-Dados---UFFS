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
    int diameter;
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

// Funções principais

void deleteProduction(Production *begin);
void changeProduction(Production *begin);
void getProduction(Production *prod);
void showProductionList(Production *begin);
void showReverseProductionList(Production *begin);
void findProductionByIdForDelete(Production *begin, int searchedId);
Production* insertProduction(Production *begin, int id, int day, int month, int year, const char *cultivar, char bundleType, int diameter, int gzBundleQuantity, float duration);

// Funções auxiliares

Production* findProductionById(Production *begin, int idToSearch);
Production* addSampleData(Production *begin);
void printProductionDetails(Production *node);
void freeProductionList(Production *begin);
void showMenu();