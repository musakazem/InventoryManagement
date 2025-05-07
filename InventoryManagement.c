#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void drawTitle();
void drawMainMenu();
void drawBorder();
void drawProductBorder();
void addProductMenu();
void clearScreen();
void flushInputBuffer();
void userStringInput();
void userIntegerInput();
void userFloatInput();
void listProducts();
void updateProductMenu();
void deleteElement();
void deleteProductMenu();
void searchProductMenu();

struct Product {
    int id;
    char name[30];
    int quantity;
    float price;
};

int main()
{
    int lastItemIndex = 0;
    int runProgram = 1;
    struct Product products[10];
    
    while (runProgram == 1) {
        clearScreen();
        drawTitle();
        printf("Total products: %d\n", lastItemIndex);

        if (lastItemIndex > 0) {
            listProducts(products, lastItemIndex);
        }

        drawMainMenu();
        int menuNumber;
        scanf_s("%d", &menuNumber);

        switch (menuNumber) {
            case 1:
                addProductMenu(products, &lastItemIndex);
                break;
            case 2:
                updateProductMenu(products, lastItemIndex);
                break;
            case 3:
                deleteProductMenu(products, &lastItemIndex);
                break;
            case 4:
                searchProductMenu(products, lastItemIndex);
                break;
            case 0:
                runProgram = 0;
                break;
            default:
                break;
        }
    }
}

void addProductMenu(struct Product products[], int *lastItemIndex) {
    clearScreen();
    printf("ADD a new product\n");
    drawBorder();
    
    struct Product item;

    printf("Product name: ");
    userStringInput(item.name, sizeof(item.name));
    
    printf("Product quantity: ");
    userIntegerInput(&item.quantity);

    printf("Product price: ");
    userFloatInput(&item.price);

    item.id = *lastItemIndex;

    products[*lastItemIndex] = item;
    *lastItemIndex += 1;

    printf("Successfully added a new product\n");
    return;
}

void updateProductMenu(struct Product products[], int lastItemIndex) {
    if (lastItemIndex > 0) {
        clearScreen();
        printf("Select product to UPDATE\n");
        drawBorder();

        listProducts(products, lastItemIndex);
        drawBorder();
        
        int idChoice;
        printf("product id: ");

        userIntegerInput(&idChoice);

        if (idChoice >= lastItemIndex) return;

        printf("Name: ");
        userStringInput(products[idChoice].name, sizeof(products[idChoice].name));

        printf("Price: ");
        userFloatInput(&products[idChoice].price);

        printf("Quantity: ");
        userIntegerInput(&products[idChoice].quantity);
    }
    return;
    
}

void deleteElement(struct Product arr[], int *arrSize, int elementId) {
    for (int i=elementId; i < *arrSize - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*arrSize)--;
    return;
}

void deleteProductMenu(struct Product products[], int *lastItemIndex) {
    if (lastItemIndex > 0) {
        clearScreen();
        printf("Select product to DELETE\n");
        drawBorder();

        listProducts(products, *lastItemIndex);
        drawBorder();

        int idChoice;
        userIntegerInput(&idChoice);
        if (idChoice >= lastItemIndex) return;
        deleteElement(products, lastItemIndex, idChoice);
    }
}

void searchProductMenu(struct Product products[], int lastItemIndex) {
    clearScreen();
    printf("Select product to DELETE\n");
    printf("Type 0 to go back to main menu\n");
    drawBorder();

    struct Product queryResult[10];
    int runSearchMenu = 1;

    while (runSearchMenu) {
        char query[30];
        printf("Input: ");
        userStringInput(query, sizeof(query));

        if (strcmp(query, "0") == 0) {
            return;
        }

        int queryResultCount = 0;

        for (int i = 0; i <= lastItemIndex; i++) {
            if (strncmp(products[i].name, query, strlen(query)) == 0) {
                if (queryResultCount < 10) {
                    queryResult[queryResultCount++] = products[i];
                }
            }
        }

        drawBorder();
        listProducts(queryResult, queryResultCount);
    }
}

void listProducts(struct Product products[], int lastItemIndex) {
    for (int i = 0; i < lastItemIndex; i++) {
        drawProductBorder();
        printf("id: %d\n", products[i].id);
        printf("name: %s\n", products[i].name);
        printf("quantity: %d\n", products[i].quantity);
        printf("price: %.2f\n", products[i].price);
    }
}

void drawMainMenu() {
    drawBorder();
    printf("1. Add \n");
    printf("2. Update \n");
    printf("3. Delete \n");
    printf("4. Search \n");
    printf("0. Quit Program \n");
 }

void drawBorder() {
    printf("********************************* \n");
}

void drawProductBorder() {
    printf("------------- \n");
}

void clearScreen() {
    system("cls");
}

void userStringInput(char str[], int size) {
    scanf_s("%s", str, size);
    flushInputBuffer();
}

void userIntegerInput(int *value) {
    scanf_s("%d", value);
    flushInputBuffer();
}

void userFloatInput(float *value) {
    scanf_s("%f", value);
    flushInputBuffer();
}

void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void drawTitle() {

    /* 
    The following tool used to draw this title: 
    https://patorjk.com/software/taag/#p=moreopts&f=Avatar&t=Inventory%20Management 
    */

    printf(
        " _____                      _                     __  __                                                   _\n"
        "|_   _|                    | |                   |  \\/  |                                                 | |\n"
        "  | |  _ ____   _____ _ __ | |_ ___  _ __ _   _  | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_\n"
        "  | | | '_ \\ \\ / / _ \\ '_ \\| __/ _ \\| '__| | | | | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|\n"
        " _| |_| | | \\ V /  __/ | | | || (_) | |  | |_| | | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_\n"
        "|_____|_| |_|\\_/ \\___|_| |_|\\__\\___/|_|   \\__, | |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|\n"
        "                                           __/ |                            __/ |\n"
        "                                          |___/                            |___/\n"
    );
}
