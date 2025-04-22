#include <stdio.h>
#include <stdlib.h>

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

struct Product {
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
    printf("Adding a new product\n");
    drawBorder();
    
    struct Product item;

    printf("Product name:\n");
    userStringInput(item.name, sizeof(item.name));
    
    printf("Product quantity:\n");
    userIntegerInput(&item.quantity);

    printf("Product price:\n");
    userFloatInput(&item.price);

    products[*lastItemIndex] = item;
    *lastItemIndex += 1;

    printf("Successfully added a new product\n");
}

void listProducts(struct Product products[], int lastItemIndex) {
    for (int i = 0; i < lastItemIndex; i++) {
        drawProductBorder();
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

void userFloatInput(int *value) {
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
