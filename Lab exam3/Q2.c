#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 256
#define MAX_SIZE 100

// Queue implementation
struct Queue {
    int front, rear;
    char arr[MAX_SIZE];
};

void enqueue(struct Queue* q, char c) {
    if (q->rear < MAX_SIZE - 1) {
        q->arr[++q->rear] = c;
    }
}

void dequeue(struct Queue* q) {
    if (q->front <= q->rear) {
        q->front++;
    }
}

char front(struct Queue* q) {
    if (q->front <= q->rear)
        return q->arr[q->front];
    return '\0';
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

void findFirstNonRepeating(char stream[]) {
    int freq[MAX_CHAR] = {0};
    struct Queue q = {0, -1};  // initialize empty queue

    for (int i = 0; stream[i]; i++) {
        char ch = stream[i];
        freq[ch]++;
        enqueue(&q, ch);

        while (!isEmpty(&q) && freq[front(&q)] > 1) {
            dequeue(&q);
        }

        if (isEmpty(&q))
            printf("-1 ");
        else
            printf("%c ", front(&q));
    }
    printf("\n");
}


int main() {
    char stream[] = "aabc";
    printf("Stream: %s\n", stream);
    printf("First non-repeating elements: ");
    findFirstNonRepeating(stream);
    return 0;
}
