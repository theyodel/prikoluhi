struct player {
    char name[101];
    int id;
    int win;
    int lose;
};

void playerStats(int id, struct player *players, int count) {
    int playerIndex = -1;

    for (int i=0; i<count; i++) {
        if (players[i].id == id) playerIndex = i;
    }

    if (playerIndex == -1) {
        printf("Игрок с ID-%d не найден!\n", id);
        return;
    }

    printf("\n");
    printf("+------+------------------------------+----------------------+----------------------+\n");
    printf("|  ID  |        Имя игрока            |     Кол-во побед     |   Кол-во поражений   |\n");
    printf("+------+------------------------------+----------------------+----------------------+\n");
    
    printf("| %4d | %28s | %20d | %20d |\n", 
        players[playerIndex].id,
        players[playerIndex].name,
        players[playerIndex].win,
        players[playerIndex].lose
    );

    printf("+------+------------------------------+----------------------+----------------------+\n");
}