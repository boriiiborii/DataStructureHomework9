#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head[10];
    bool visited[10];
} Graph;

// 그래프 초기화 함수
void initializeGraph(Graph* graph) {
    for (int i = 0; i < 10; i++) {
        graph->head[i] = NULL; // 그래프헤더를 Null로 지정하여 연결 끊어주기
        graph->visited[i] = false; // 초기화를 할때 visited true였던 데이터들을 false로 바꿔주기
    }
}

// 노드 생성 함수
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node)); //동적할당
    newNode->vertex = vertex; // 값 넣기
    newNode->next = NULL; // 새로 생성한거니까 넥스트는 NULL
    return newNode;
}

// 간선 삽입
void insertEdge(Graph* graph, int src, int dst) {
    Node* newNode = createNode(dst);
    
    // 리스트 끝에 노드 추가
    if (graph->head[src] == NULL) {
        graph->head[src] = newNode;
    } else {
        Node* temp = graph->head[src];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 반대 간선 추가
    newNode = createNode(src);
    if (graph->head[dst] == NULL) {
        graph->head[dst] = newNode;
    } else {
        Node* temp = graph->head[dst];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 그래프 프린트
void printGraph(Graph* graph) {
    for (int i = 0; i < 10; i++) {//노드를 돌아가며 반복
        Node* tmp = graph->head[i]; // 노드를 돌기
        printf("vertex %d:", i);
        while (tmp != NULL) {  // 마지막 노드가 아니라면 
            printf(" %d >", tmp->vertex);
            tmp = tmp->next;
        }
        printf("null\n");
    }
}

// DFS 함수
void DFS(Graph* graph, int vertex) {
    // 비효율적인 방식으로 방문 체크
    for (int i = 0; i < 10; i++) {
        if (i == vertex) {
            graph->visited[i] = true;
            break;
        }
    }
    printf("visited %d\n", vertex);

    Node* temp = graph->head[vertex];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!graph->visited[connectedVertex]) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// 방문 초기화 함수
void resetVisited(Graph* graph) {
    for (int i = 0; i < 10; i++) {
        graph->visited[i] = false;//전부 방문 false
    }
}

// BFS 함수
void BFS(Graph* graph, int startVertex) {
    int queue[10];
    int front = 0, rear = 0;

    graph->visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("visited %d\n", currentVertex);

        Node* temp = graph->head[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    printf("[----- [LEEHWAJIN] [2020037103] -----]\n");

    Graph graph;
    initializeGraph(&graph);

    char choice;
    int src, dst;

    while (1) {
        printf("\nInitialize Graph: z\n");
        printf("Insert Vertex: v\n");
        printf("Depth First Search: d\n");
        printf("Print Graph: p\n");
        printf("Insert Edge: e\n");
        printf("Breath First Search: b\n");
        printf("Quit: q\n");
        scanf(" %c", &choice);

        if (choice == 'z') {
            initializeGraph(&graph);
            printf("초기화 완료.\n");
        } else if (choice == 'e') {
            printf("시작과 끝을 정해주세요. (0부터 9 사이 숫자 /시작 끝/ 형식으로 입력하세요)");
            scanf("%d %d", &src, &dst);
            if (src < 0 || src >= 10 || dst < 0 || dst >= 10) {
                printf("0부터 9사이의 숫자만 가능해요.\n");
                continue;
            }
            insertEdge(&graph, src, dst);
            printf("완료\n");
        } else if (choice == 'p') {
            printGraph(&graph);
        } else if (choice == 'd') {
            printf("시작점 입력하세요: ");
            scanf("%d", &src);
            if (src < 0 || src >= 10) {
                printf("0부터 9사이 숫자만 가능합니다.\n");
                continue;
            }
            resetVisited(&graph);
            DFS(&graph, src);
        } else if (choice == 'b') {
            printf("시작점을 입력하세요: ");
            scanf("%d", &src);
            if (src < 0 || src >= 10) {
                printf("0부터 9사이 숫자만 가능합니다.\n");
                continue;
            }
            resetVisited(&graph);
            BFS(&graph, src);
        } else if (choice == 'q') {
            break;
        } else {
            printf("제대로 입력하세요.\n");
        }
    }

    return 0;
}