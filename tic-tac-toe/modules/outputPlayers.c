struct player {
    char name[101];
    int id;
    int win;
    int lose;
};

void outputPlayers(struct player *players, int count) {
    if (count == 0) {
        printf("Игроки не введены!\n");
        return;
    }
    printf("Всего игроков: %d\n", count);
    printf("+------+------------------------------+----------------------+----------------------+\n");
    printf("|  ID  |        Имя игрока            |     Кол-во побед     |   Кол-во поражений   |\n");
    printf("+------+------------------------------+----------------------+----------------------+\n");
    
    for (int i=0; i<count; i++) {
        printf("| %4d | %28s | %20d | %20d |\n", 
            players[i].id, 
            players[i].name, 
            players[i].win, 
            players[i].lose);
    }

    printf("+------+------------------------------+----------------------+----------------------+\n");
}