#include <stdio.h>
#include <stdlib.h>

void drawTitle();
void drawMainMenu();
void drawBorder();
void addProductMenu();
void clearScreen();

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
    fgets(item.name, sizeof(item.name), stdin);

    printf("Product price:\n");
    scanf_s("%f", &item.price);

    printf("Product quantity:\n");
    scanf_s("%d", &item.quantity);

    products[*lastItemIndex] = item;
    *lastItemIndex += 1;

    printf("Successfully added a new product");
}

void drawMainMenu() {
    drawBorder();
    printf("1. Add \n");
    printf("2. Update \n");
    printf("3. Delete \n");
    printf("0. Quit Program \n");
}

void drawBorder() {
    printf("------------------------------------ \n");
}

void clearScreen() {
    system("cls");
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
