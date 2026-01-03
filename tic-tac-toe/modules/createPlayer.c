struct player {
    char name[101];
    int id;
    int win;
    int lose;
};


struct player* createPlayer (int count, struct player *players) {
// Увеличиваем количество игроков
    int new_count = count + 1;
    
    // Выделяем память под новый массив
    struct player *newPlayers = (struct player*) malloc(sizeof(struct player) * new_count);
    
    if (newPlayers == NULL) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    
    // Копируем старых игроков в новый массив
    for (int i = 0; i < count; i++) {
        newPlayers[i] = players[i];
    }
    
    // Освобождаем старый массив (если он существовал)
    if (players != NULL) {
        free(players);
    }
    
    // Добавляем нового игрока
    printf("Введите имя игрока: ");
    fflush(stdin); // Очищаем буфер ввода
    fgets(newPlayers[count].name, 101, stdin);
    
    // Удаляем символ новой строки из имени, если он есть
    int len = strlen(newPlayers[count].name);
    if (len > 0 && newPlayers[count].name[len - 1] == '\n') {
        newPlayers[count].name[len - 1] = '\0';
    }
    
    newPlayers[count].id = count + 1; // ID начинаются с 1
    newPlayers[count].win = 0;
    newPlayers[count].lose = 0;
    
    // Обновляем счетчик
    count = new_count;
    
    return newPlayers;
}