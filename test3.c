#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

int n, m;
int graph[MAX_SIZE][MAX_SIZE];

// 구조체 저의
typedef struct {
    int x;
    int y;
} Node;

// 큐배열생성(최대칸수 200*200 = 40000=> 40005로)
Node queue[40005];
int front = 0;
int rear = 0;

//큐 삽입
void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

//큐 삭제
Node dequeue() {
    return queue[front++];
}

// 상하좌우 4가지 이동방향
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int start_x, int start_y) {
    enqueue(start_x, start_y);

    while (front < rear) {
        Node current = dequeue();
        int x = current.x;
        int y = current.y;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 미로 벗어남
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            // 괴물(0)있는칸
            if (graph[nx][ny] == 0) {
                continue;
            }
            // 해당 노드를 처음 방문하는 경우=>최단 거리 기록
            if (graph[nx][ny] == 1) {
                graph[nx][ny] = graph[x][y] + 1;
                enqueue(nx, ny);
            }
        }
    }
    return graph[n - 1][m - 1];
}

int main(void) {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        char row[MAX_SIZE + 5];
        scanf("%s", row);
        
        for (int j = 0; j < m; j++) {
            // 문자를 숫자로
            graph[i][j] = row[j] - '0';
        }
    }
    

    printf("%d\n", bfs(0, 0));
    
    return 0;
}