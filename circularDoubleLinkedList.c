#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

static unsigned int depth;

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

void createFirstNode( struct Node **node, int value );

int main()
{
  depth = 0;
  struct Node *head = (struct Node *)malloc( sizeof( struct Node ) );
  createFirstNode( &head, 1 );

  return 0;
}

void createFirstNode( struct Node **node, int value )
{
  ++depth;
  (*node)->data = value;
  (*node)->next = *node; // Points at itself
  (*node)->prev = *node; // Points at itself

  printf( "List depth = %u\n", depth );
  printf( "Node id: %x -> { %d, %x, %x }\n", *node, (*node)->data, (*node)->next, (*node)->prev );


  return;
}
