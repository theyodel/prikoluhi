#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct route {
    int number;
    float price;
    char startPoint[101];
    char endPoint[101];
    int time;
    char busType[101];
};

struct route* inputRoutes(int n) {
    if (n < 1) {
        printf("Error: Колическтво маршрутов должно быть больше 0!\n");
        printf("Function closed with   \" NULL \"   return\n");
        return NULL;
    }

    struct route *routes = (struct route*) malloc(n * sizeof(struct route));
    
    if (routes == NULL)
    {
        printf("Error: Ошибка выделения памяти!\n");
        printf("Function closed with   \" NULL \"   return\n");
        return NULL;
    }
    

    printf("Введите %d маршрутов: \n-----------------------------------\n", n);
    for (int i=0; i<n; i++) {
        printf("Введите номер маршрута: ");
        scanf("%d", &routes[i].number);
        while (getchar() != '\n');

        printf("Введите начальную точку маршрута (до 100 символов): ");
        gets(routes[i].startPoint); 
        if (strcmp(routes[i].startPoint, "")==0) {
            strcpy(routes[i].startPoint, "N/A");
        }

        printf("Введите конечную точку маршрута (до 100 символов): ");
        gets(routes[i].endPoint);
        if (strcmp(routes[i].endPoint, "")==0) {
            strcpy(routes[i].endPoint, "N/A");
        }

        printf("Введите марку автобуса: ");
        gets(routes[i].busType);
        if (strcmp(routes[i].busType, "")==0) {
            strcpy(routes[i].busType, "N/A");
        }

        printf("Введите цену проезда: ");
        scanf("%f", &routes[i].price);

        printf("Введите время в пути (в минутах): ");
        scanf("%d", &routes[i].time);

        printf("----------------------------------------------\n");
    }

    return routes;
}