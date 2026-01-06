// Main includes (header files)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

// Modules
#include "./modules/createPlayer.c"
#include "./modules/outputPlayers.c"
#include "./modules/playerStats.c"
#include "./modules/runGame.c"

struct player {
    char name[101];
    int id;
    int win;
    int lose;
};

int main() {
    system("chcp 1251 > nul");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");

    int choice, count=0, totalGames=0, idCross, idCircle;
    struct player *players = NULL;

    while (1) {
        printf("\n\n======= МЕНЮ =======\n");
        printf("1. Начать игру\n");
        printf("2. Ввести нового игрока\n");
        printf("3. Получить статистику игрока\n");
        printf("4. Вывести список всех игроков\n");
        printf("0. Выход\n");
        printf("-> ");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice) {
            case 1:
                if (count < 2) printf("Недостаточно игроков (необходимо минимум 2 игрока). \nИгроков на данный момент - %d", count);
                else {
                    printf("Введите ID игрока, который будет играть за команду \"Крестики\": ");
                    scanf("%d", &idCross);
                    printf("Введите ID игрока, который будет играть за команду \"Нолики\": ");
                    scanf("%d", &idCircle);
                    runGame(idCross, idCircle, &totalGames, players, count);
                }
                break;

            case 2:
                players = createPlayer(count, players);
                count++;
                break;

            case 3:
                int id = -1;
                printf("Введите ID игрока: ");
                scanf("%d", &id);
                if (id < 0) {
                    printf("Ошибка! ID игрока не может быть отрицательным числом!\n");
                }
                else {
                    playerStats(id, players, count);
                }
                break;
            
            case 4:
                outputPlayers(players, count);
                break;
                
            case 0:
                if (players != NULL) free(players);
                printf("Выход из программы. . .\n");
                return 0;

            default:
                printf("Неправильный выбор! Попробуйте снова.\n");
                break;
        }
    }
}