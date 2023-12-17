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
void addProduction(Production **begin);
void updateProductionData(Production *target);
void changeProduction(Production *begin);
void getProduction(Production *prod);
void deleteProduction(Production *begin);
void showProductionList(Production *begin);
void showReverseProductionList(Production *begin);

// Funções auxiliares
Production* findProductionById(Production *begin, int idToSearch);
void printProductionDetails(Production *node);
void freeProductionList(Production *begin);
void showMenu();
int isFarmValid(const char *cultivar);
int isProductionCodeDuplicate(Production *begin, int newId);
int isBundleTypeValid(char bundleType);
void findProductionByIdForDelete(Production *begin, int searchedId);