// Headers
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


// Data declarations
static unsigned int depth;

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};


// Forward function declarations
void createFirstNode( struct Node **head, struct Node ** tail, int value );
void pushNodeFront( struct Node **head, struct Node **tail, int value );
void pushNodeBack( struct Node **head, struct Node **tail, int value );
void insertAfterNode( struct Node **head, int data, int newData );
void printList( struct Node *head );
void printListReversed( struct Node *tail );


//Function implementations
int main()
{
  depth = 0;
  struct Node *head = (struct Node *)malloc( sizeof( struct Node ) );
  struct Node *tail = (struct Node *)malloc( sizeof( struct Node ) );

  printf( "\n&Head: %x, &Tail %x", &head, &tail );

  createFirstNode( &head, &tail, 10 );
  printList( head );

  printf( "--------------------------------------------------------------------\n" );
  pushNodeFront( &head, &tail, 20 );
  printList( head );
  printf( "\nHead: %x, Tail: %x\n", head, tail );

  printf( "--------------------------------------------------------------------\n" );
  pushNodeBack( &head, &tail, 30 );
  printList( head );
  printf( "\nHead: %x, Tail: %x\n", head, tail );

  printf( "--------------------------------------------------------------------\n" );
  pushNodeFront( &head, &tail, 50 );
  printList( head );
  printf( "\nHead: %x, Tail: %x\n", head, tail );

  printf( "--------------------------------------------------------------------\n" );
  pushNodeBack (&head, &tail, 80 );
  printList( head );
  printf( "\nHead: %x, Tail: %x\n", head, tail );
  printf( "--------------------------------------------------------------------\n" );

  printf( "head->prev: %x, head->next: %x\n", head->prev, head->next );
  printf( "tail->prev: %x, tail->next: %x\n", tail->prev, tail->next );
  printf( "--------------------------------------------------------------------\n" );

  printListReversed( tail );

  printf( "--------------------------------------------------------------------\n" );
  insertAfterNode (&head, 10, 120 );
  printList( head );
  printf( "\nHead: %x, Tail: %x\n", head, tail );
  printf( "--------------------------------------------------------------------\n" );

  printListReversed( tail );
  return 0;
}


void createFirstNode( struct Node **head, struct Node **tail, int value )
{
  ++depth;

  (*head)->data = value;
  (*head)->next = *head; // Points at itself
  (*head)->prev = *head; // Points at itself

  //
  // Since only one node exists at this point, head and tail are the same
  //
  *tail = *head;

  printf( "\n--------------------------------------------------------------------\n" );
  printf( "List depth = %u\n", depth );
  printf( "\nNode id: %x -> { %d, %x, %x }\n", *head, (*head)->data, (*head)->next, (*head)->prev );
  printf( "\nHead: %x, Tail: %x\n", *head, *tail );
  printf( "&Head: %x, &Tail %x\n", head, tail );
  printf( "\nList status:\n" );

  return;
}


void pushNodeFront( struct Node **head, struct Node **tail, int value )
{
  ++depth;

  struct Node *newNode = (struct Node *)malloc(sizeof (struct Node) );

  newNode->prev = *tail;
  newNode->next = *head;
  newNode->data = value;

  (*head)->prev = newNode;
  (*tail)->next = newNode;

  *head = newNode;
}


void pushNodeBack( struct Node **head, struct Node **tail, int value )
{
  ++depth;

  struct Node *newNode = (struct Node *)malloc(sizeof (struct Node) );

  newNode->prev = *tail;
  newNode->next = *head;
  newNode->data = value;

  (*head)->prev = newNode;
  (*tail)->next = newNode;

  *tail = newNode;
}


void insertAfterNode( struct Node **head, int data, int newData )
{
  ++depth;

  struct Node *newNode  = (struct Node *)malloc( sizeof( struct Node ) );
  struct Node *tempNode = *head;

  int value;

  do
  {
    value = tempNode->data;

    if ( value == data )
    {
      newNode->next = tempNode->next;
      newNode->prev = tempNode;
      newNode->data = newData;

      tempNode->next->prev = newNode;
      tempNode->next       = newNode;

      return;
    }
    else
    {
    tempNode = tempNode->next;
    }

  } while( tempNode != *head );

  printf("The value: %d is not in the list\n", data);
}


void printList( struct Node *head )
{
  struct Node *auxNode = (struct Node *)malloc( sizeof( struct Node ) );
  auxNode = head;

  do
  {
    printf( "%x %d\n", auxNode, auxNode->data );

    auxNode = auxNode->next;
  } while ( auxNode != head );

  return;
}

void printListReversed( struct Node *tail )
{
  struct Node *auxNode = (struct Node *)malloc( sizeof( struct Node ) );
  auxNode = tail;

  do
  {
    printf( "%x %d\n", auxNode, auxNode->data );

    auxNode = auxNode->prev;
  } while ( auxNode != tail );

  return;
}
