#include <stdio.h>
#include "queue.h"
#include "quick_select.h"

int main() {
    Queue *q = newQueue(10);
    enqueue(q, 3);
    enqueue(q, 10);
    enqueue(q, 1);
    enqueue(q, 4);
    enqueue(q, 20);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 4);
    enqueue(q, 4);
    enqueue(q, 4);
    enqueue(q, 7);
    enqueue(q, 9);
    enqueue(q, 15);
    enqueue(q, 19);


    resetOffset(q);
    while (hasNext(q)) {
        printf("%.1f\n", next(q));
    }

    printf("\n\nsize: %d\n\n", q->size);

    for (int i = 0; i < q->size; i++) {
        printf("%.1f\n", q->items[i]);
    }

    int kThSmallest = 5;

    float median = sel(q->items, 0, q->size - 1, kThSmallest);

    printf("\n\n");
    printf("%dth smallest: %.1f", kThSmallest, median);


    printf("\n\nafter finding %dth smallest:\n", kThSmallest);

    for (int i = 0; i < q->size; i++) {
        printf("%.1f\n", q->items[i]);
    }

    return 0;
}