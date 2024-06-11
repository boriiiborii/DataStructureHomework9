#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head[10];
    bool visited[10];
} Graph;

//그래프를 초기화(아예 없애는 코드)
void initializeGraph(Graph* graph) {
    for (int i = 0; i < 10; i++) {
        graph->head[i] = NULL; //헤드 널처리 해서 연결 끊기
        graph->visited[i] = false; //방문한것또한 모두 false로 바꾸기
    }
}


int main() {
    printf("[----- [hwajin]  [2020037103] -----]\n");

    Graph graph;
    initializeGraph(&graph);

    char choice;
    do {
        printf("\n----------------------------------------\n");
        printf("              Graph Searches\n");
        printf("----------------------------------------\n");
        printf(" Initialize Graph = z\n");
        printf(" Insert Vertex = v\n");
        printf(" Depth First Search = d\n");
        printf(" Print Graph\n = p");
        printf(" Insert Edge = e\n");
        printf(" Breath First Search = b\n");
        printf(" Quit = q\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'z': ; 
                initializeGraph(&graph);
                printf("그래프 초기화 완료.\n");
                break;
            case 'v': ; 
                
                break;
            case 'd': 
               
                break;
            case 'p': ; 

                break;
            case 'e': ; 

                break;
            case 'b': ; 

                break;
            case 'q': ; 
            
                break;
            default:
                printf("다시입력해주세요\n");
        }
    } while (choice != 'q');

    return 0;
}

