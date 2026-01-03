#include <stdio.h>

struct player {
    char name[101];
    int id;
    int win;
    int lose;
};

// Структура для хранения состояния доски
struct gameState {
    char board[3][3];
    int currentPlayer;  // 0 - крестики, 1 - нолики
    int movesCount;
    int winner;  // -1 - игра продолжается, 0 - ничья, 1 - крестики, 2 - нолики
};

// Вспомогательные функции для игры
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[3][3]) {
    printf("\n   1    2    3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d  ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) printf("  | ");
        }
        printf("\n");
        if (i < 2) printf("  ----+----+----\n");
    }
    printf("\n");
}

int checkWinner(char board[3][3]) {
    // Проверка строк
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == 'X') ? 1 : 2;
        }
    }
    
    // Проверка столбцов
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return (board[0][j] == 'X') ? 1 : 2;
        }
    }
    
    // Проверка диагоналей
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == 'X') ? 1 : 2;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == 'X') ? 1 : 2;
    }
    
    // Проверка на ничью
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return -1;
        }
    }
    
    return 0;  // Ничья
}

int isValidMove(char board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Основная функция игры
void runGame(int idCross, int idCircle, int *totalGames, struct player *players, int playerCount) {
    // Поиск ИНДЕКСОВ игроков в массиве
    int crossIndex = -1;
    int circleIndex = -1;
    
    for (int i = 0; i < playerCount; i++) {
        if (players[i].id == idCross) {
            crossIndex = i;  // Сохраняем индекс, а не ID
        }
        if (players[i].id == idCircle) {
            circleIndex = i;  // Сохраняем индекс, а не ID
        }
    }
    
    if (crossIndex == -1 || circleIndex == -1) {
        printf("Ошибка: один из игроков не найден!\n");
        return;
    }
    
    // Инициализация игры
    struct gameState game;
    initializeBoard(game.board);
    game.currentPlayer = 0;  // Первыми ходят крестики
    game.movesCount = 0;
    game.winner = -1;
    
    printf("\n======= ИГРА #%d =======\n", *totalGames + 1);
    printf("[ X ] Крестики: %s (ID: %d)\n", players[crossIndex].name, players[crossIndex].id);
    printf("[ O ] Нолики: %s (ID: %d)\n", players[circleIndex].name, players[circleIndex].id);
    printf("\nНачинаем игру!\n");
    
    // Основной игровой цикл
    while (game.winner == -1) {
        printBoard(game.board);
        
        // Определяем текущего игрока
        struct player *currentPlayer = (game.currentPlayer == 0) ? &players[crossIndex] : &players[circleIndex];
        char playerSymbol = (game.currentPlayer == 0) ? 'X' : 'O';
        
        printf("Ходит %s (%c). Введите строку и столбец (например, 1 2): ", 
               currentPlayer->name, playerSymbol);
        
        int row, col;
        scanf("%d%d", &row, &col);
        row--;  // Переводим в 0-индексацию
        col--;
        
        // Очистка буфера ввода
        while (getchar() != '\n');
        
        // Проверка хода
        if (!isValidMove(game.board, row, col)) {
            printf("Неверный ход! Попробуйте снова.\n");
            continue;
        }
        
        // Выполнение хода
        game.board[row][col] = playerSymbol;
        game.movesCount++;
        game.currentPlayer = !game.currentPlayer;  // Смена игрока
        
        // Проверка состояния игры
        game.winner = checkWinner(game.board);
    }
    
    // Вывод финального состояния доски
    printBoard(game.board);
    
    // Обновление статистики
    (*totalGames)++;
    
    if (game.winner == 1) {  // Победили крестики
        printf("Победили КРЕСТИКИ! %s выигрывает!\n", players[crossIndex].name);
        players[crossIndex].win++;
        players[circleIndex].lose++;
    } else if (game.winner == 2) {  // Победили нолики
        printf("Победили НОЛИКИ! %s выигрывает!\n", players[circleIndex].name);
        players[circleIndex].win++;
        players[crossIndex].lose++;
    } else {  // Ничья
        printf("НИЧЬЯ! Никто не победил.\n");
    }
    
    printf("\nСтатистика после игры:\n");
    printf("[ X ] %s: %d побед, %d поражений\n", players[crossIndex].name, players[crossIndex].win, players[crossIndex].lose);
    printf("[ O ] %s: %d побед, %d поражений\n", players[circleIndex].name, players[circleIndex].win, players[circleIndex].lose);
}