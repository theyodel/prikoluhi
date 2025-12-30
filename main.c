#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// Modules
#include "./modules/inputRoutes.c"
#include "./modules/outputRoutes.c"
#include "./modules/sortRoutesPrice.c"
#include "./modules/sortRoutesTime.c"
#include "./modules/routeInfo.c"

struct route {
    int number;
    float price;
    char startPoint[101];
    char endPoint[101];
    int time;
    char busType[101];
};

int main() {
    system("chcp 1251 > nul");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");

    int n, choice;
    struct route *routes = NULL;

    while (1) {
        printf("\n\n======= М Е Н Ю =======\n");
        printf("1. Ввести маршруты\n");
        printf("2. Вывести маршруты\n");
        printf("3. Отсортировать маршруты по цене\n");
        printf("4. Отсортировать маршруты по времени\n");
        printf("5. Вывести информацию по номеру маршрута\n");
        printf("0. Выход из программы\n");
        printf("-> ");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice)
        {
        case 1:
            if (routes != NULL) {
                free(routes);
            }

            printf("Введите кол-во маршрутов: ");
            scanf("%d", &n);
            
            routes = inputRoutes(n);
            break;
        

        case 2:
            if (routes == NULL) {
                printf("Error: Маршруты не введены!");
            }
            else {
                outputRoutes(routes, n);
            }
            break;
        
        case 3:
            if (routes == NULL) {
                printf("Error: Маршруты не введены!");
            }
            else {
                sortRoutesPrice(routes, n);
            }
            break;
        
        case 4:
            if (routes == NULL) {
                printf("Error: Маршруты не введены!");
            }
            else {
                sortRoutesTime(routes, n);
            }
            break;

        case 5:
            if (routes == NULL) {
                printf("Error: Маршруты не введены!");
            }
            else {
                routeInfo(routes, n);
            }
            break;
        
        case 0:
            if (routes != NULL) {
                free(routes);
                printf("Память очищена.\n");
            }

            printf("Выход из программы...");
            return 0;

        default:
            printf("Ошибка выбора. Попробуйте снова\n");
            break;
        }
    }
}