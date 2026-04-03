/*Keys and Rooms*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int** rooms, int* roomsColSize, bool* visited, int room) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(rooms, roomsColSize, visited, key);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));

    dfs(rooms, roomsColSize, visited, 0);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}

int main() {
    int n;
    printf("Enter number of rooms: ");
    scanf("%d", &n);

    int** rooms = (int**)malloc(n * sizeof(int*));
    int* roomsColSize = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter number of keys in room %d: ", i);
        scanf("%d", &roomsColSize[i]);

        rooms[i] = (int*)malloc(roomsColSize[i] * sizeof(int));

        printf("Enter keys: ");
        for (int j = 0; j < roomsColSize[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    if (canVisitAllRooms(rooms, n, roomsColSize)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    for (int i = 0; i < n; i++) {
        free(rooms[i]);
    }
    free(rooms);
    free(roomsColSize);

    return 0;
}