#include "queue.h"

queue* queue_create() {
  queue* q = malloc(sizeof(queue));
  memset(q, 0, sizeof(queue));
  return q;
}

void queue_push(queue* queue, void* item) {
  node_t* tail = queue->tail;
  node_t* next = malloc(sizeof(node_t));

  next->next = NULL;
  next->value = item;

  if (tail) {
    tail->next = next;
  } else {
    queue->head = next;
  }
  queue->tail = next;
}

void* queue_pop(queue* queue) {
  node_t* head = queue->head;
  if (head) {
    queue->head = head->next;
    void* item = head->value;
    if (!head->next)
      queue->tail = NULL;
    free(head);
    return item;
  }
  return NULL;
}


void queue_destroy(queue* queue) {
  node_t* next = queue->head;
  while (next) {
    node_t* tmp = next->next;
    free(next);
    next = tmp;
  }
  free(queue);
}
