#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;
} Deque;

Deque* createDeque(int capacity) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->arr = (int*)malloc(sizeof(int) * capacity);
    dq->capacity = capacity;
    dq->front = -1;
    dq->rear = 0;
    dq->count = 0;
    return dq;
}

bool empty(Deque* dq) {
    return dq->count == 0;
}

int size(Deque* dq) {
    return dq->count;
}

bool push_front(Deque* dq, int value) {
    if (dq->count == dq->capacity)
        return false;

    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0) {
        dq->front = dq->capacity - 1;
    }
    else {
        dq->front--;
    }

    dq->arr[dq->front] = value;
    dq->count++;
    return true;
}

bool push_back(Deque* dq, int value) {
    if (dq->count == dq->capacity)
        return false;

    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    }
    else if (dq->rear == dq->capacity - 1) {
        dq->rear = 0;
    }
    else {
        dq->rear++;
    }

    dq->arr[dq->rear] = value;
    dq->count++;
    return true;
}

bool pop_front(Deque* dq) {
    if (empty(dq))
        return false;

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    }
    else if (dq->front == dq->capacity - 1) {
        dq->front = 0;
    }
    else {
        dq->front++;
    }

    dq->count--;
    return true;
}

bool pop_back(Deque* dq) {
    if (empty(dq))
        return false;

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    }
    else if (dq->rear == 0) {
        dq->rear = dq->capacity - 1;
    }
    else {
        dq->rear--;
    }

    dq->count--;
    return true;
}

int front(Deque* dq) {
    if (empty(dq))
        return -1;
    return dq->arr[dq->front];
}

int back(Deque* dq) {
    if (empty(dq))
        return -1;
    return dq->arr[dq->rear];
}

void display(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    int i = dq->front;
    int cnt = dq->count;

    while (cnt--) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % dq->capacity;
    }
    printf("\n");
}

void freeDeque(Deque* dq) {
    free(dq->arr);
    free(dq);
}

int main() {
    Deque* dq = createDeque(10);

    push_back(dq, 10);
    push_back(dq, 20);
    push_front(dq, 5);
    push_front(dq, 2);

    display(dq);

    printf("Front: %d\n", front(dq));
    printf("Back: %d\n", back(dq));
    printf("Size: %d\n", size(dq));

    pop_front(dq);
    pop_back(dq);

    display(dq);

    freeDeque(dq);

    return 0;
}
