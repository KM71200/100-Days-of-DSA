/**/

#include <stdio.h>
#include <string.h>

#define MAX 100
#define ALPHA 26

int adj[ALPHA][ALPHA];
int indegree[ALPHA];
int present[ALPHA];
int queue[ALPHA];

int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);

    char words[MAX][MAX];

    printf("Enter words:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    for (int i = 0; i < ALPHA; i++) {
        indegree[i] = 0;
        present[i] = 0;
        for (int j = 0; j < ALPHA; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        char *s1 = words[i];
        char *s2 = words[i + 1];

        int len1 = strlen(s1);
        int len2 = strlen(s2);
        int len = len1 < len2 ? len1 : len2;

        int found = 0;

        for (int j = 0; j < len; j++) {
            if (s1[j] != s2[j]) {
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';

                if (adj[u][v] == 0) { 
                    adj[u][v] = 1;
                    indegree[v]++;
                }

                found = 1;
                break;
            }
        }

        if (!found && len1 > len2) {
            printf("Invalid dictionary (prefix issue)\n");
            return 0;
        }
    }

    for (int i = 0; i < ALPHA; i++) {
        if (present[i] && indegree[i] == 0) {
            enqueue(i);
        }
    }

    char result[ALPHA];
    int idx = 0;

    while (!isEmpty()) {
        int node = dequeue();
        result[idx++] = node + 'a';

        for (int j = 0; j < ALPHA; j++) {
            if (adj[node][j]) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }

    int total = 0;
    for (int i = 0; i < ALPHA; i++) {
        if (present[i]) total++;
    }

    if (idx != total) {
        printf("Cycle detected! Invalid order.\n");
        return 0;
    }

    printf("Character Order: ");
    for (int i = 0; i < idx; i++) {
        printf("%c ", result[i]);
    }

    return 0;
}