#include <stdio.h>
#include <stdlib.h>

struct route {
    int number;
    float price;
    char startPoint[101];
    char endPoint[101];
    int time;
    char busType[101];
};

void sortRoutesPrice(struct route *routes, int n) {
    struct route temp;
    int choice;

    printf("1. Отсортировать по убыванию (max -> min)\n");
    printf("2. Отсортировать по возрастанию (min -> max)\n");
    printf("-> ");
    scanf("%d", &choice);
    printf("\n");

    for (int i = 0; i < n; i++) {
        routes[i] = routes[i];
    }

    while (1) {
        switch (choice) {
            case 1:
                for (int j = n; j > 1; j--) {
                    for (int i = 0; i < j-1; i++) {
                        if (routes[i].price < routes[i+1].price) {
                            temp=routes[i];
                            routes[i]=routes[i+1];
                            routes[i+1]=temp;
                        }
                    }
                }
                printf("Отсоритровано по убыванию: \n");
                outputRoutes(routes, n);
                return;

            case 2:
                for (int j = n; j > 1; j--) {
                    for (int i = 0; i < j-1; i++) {
                        if (routes[i].price > routes[i+1].price) {
                            temp=routes[i];
                            routes[i]=routes[i+1];
                            routes[i+1]=temp;
                            }
                    }
                }
                printf("Отсоритровано по возрастанию: \n");
                outputRoutes(routes, n);
                return;
            
            default:
                printf("Ошибка выбора. Попробуйте снова\n");
                break;
        }
    }
}