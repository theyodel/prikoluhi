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

void routeInfo(struct route *routes, int n) {
    int number, flag=0, routeIndex;
    char toHours[20], toMins[20];

    printf("Введите номер маршрута: ");
    scanf("%d", &number);

    for (int i = 0; i<n; i++) {
        if (routes[i].number == number) {
            routeIndex = i;
            flag = 1;
        }
    }

    if (flag == 0) {
        printf("Error: Маршрут с номерои %d не найден!\n", number);
        printf("Function closed with   \" N/A \"   return\n");
        return;
    }

    printf("\n+------+------------------------------+----------------------+----------------------+------------+---------------+\n");
    printf("|  No  |        Марка автобуса        |   Начальная точка    |   Конечная точка     |    Цена    |  Время в пути |\n");
    printf("+------+------------------------------+----------------------+----------------------+------------+---------------+\n");
    printf("| %4d | %28s | %20s | %20s | %9.2fр | ",
               routes[routeIndex].number,
               routes[routeIndex].busType,
               routes[routeIndex].startPoint,
               routes[routeIndex].endPoint,
               routes[routeIndex].price);
    
    if (routes[routeIndex].time % 60 == 0) {
            printf("%2sч%10s", itoa(routes[routeIndex].time/60, toHours, 10), " ");
        }
        else if (routes[routeIndex].time < 60) {
            printf("%2sмин%8s", itoa(routes[routeIndex].time, toMins, 10), " ");
        }
        else {
            printf("%2sч %2sмин%4s", itoa(routes[routeIndex].time/60, toHours, 10), itoa(routes[routeIndex].time%60, toMins, 10), " ");
        }
        
        // Закрываем строку таблицы
    printf(" |\n");
    
    printf("+------+------------------------------+----------------------+----------------------+------------+---------------+\n");
    
}