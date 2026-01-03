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

void outputRoutes(struct route *routes, int n) {
    char toHours[20], toMins[20];
    printf("+------+------------------------------+----------------------+----------------------+------------+---------------+\n");
    printf("|  No  |        Марка автобуса        |   Начальная точка    |   Конечная точка     |    Цена    |  Время в пути |\n");
    printf("+------+------------------------------+----------------------+----------------------+------------+---------------+\n");
    
    for (int i = 0; i < n; i++) {
        // Выводим все, кроме времени
        printf("| %4d | %28s | %20s | %20s | %9.2fр | ",
               routes[i].number,
               routes[i].busType,
               routes[i].startPoint,
               routes[i].endPoint,
               routes[i].price);
        
        // Выводим время в зависимости от условий
        if (routes[i].time % 60 == 0) {
            printf("%2sч%10s", itoa(routes[i].time/60, toHours, 10), " ");
        }
        else if (routes[i].time < 60) {
            printf("%2sмин%8s", itoa(routes[i].time, toMins, 10), " ");
        }
        else {
            printf("%2sч %2sмин%4s", itoa(routes[i].time/60, toHours, 10), itoa(routes[i].time%60, toMins, 10), " ");
        }
        
        // Закрываем строку таблицы
        printf(" |\n");
    }
    
    printf("+------+------------------------------+----------------------+----------------------+------------+---------------+\n");
    printf("\nВсего маршрутов: %d\n", n);
}