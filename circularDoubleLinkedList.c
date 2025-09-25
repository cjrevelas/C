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
void insertAfterNode( struct Node **head, struct Node **tail, int data, int newData );
void printList( struct Node *head, struct Node *tail );
void printListReversed( struct Node *tail );


//Function implementations
int main()
{
  depth = 0;
  struct Node *head = (struct Node *)malloc( sizeof( struct Node ) );
  struct Node *tail = (struct Node *)malloc( sizeof( struct Node ) );

  printf( "\n&Head: %x, &Tail %x\n", &head, &tail );
  printf( " Head: %x,  Tail %x\n",  head,  tail );

  printf("\n\n");

  printf("--> Creating the first node with value 10\n");
  createFirstNode( &head, &tail, 10 );
  printList( head, tail );

  printf("--> Pushing front the value 20\n");
  pushNodeFront( &head, &tail, 20 );
  printList( head, tail );

  printf("--> Pushing back the value 30\n");
  pushNodeBack( &head, &tail, 30 );
  printList( head, tail );

  printf("--> Pushing front the value 50\n");
  pushNodeFront( &head, &tail, 50 );
  printList( head, tail );

  printf("--> Pushing back the value 80\n");
  pushNodeBack (&head, &tail, 80 );
  printList( head, tail );

  printf("--> Inserting value 120 after value 80\n");
  insertAfterNode (&head, &tail, 80, 120 );
  printList( head, tail );

  printf("--> Printing list values in reversed order\n");
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


void insertAfterNode( struct Node **head, struct Node **tail, int data, int newData )
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

      //
      // If tempNode is the tail, i.e., head->prev, then
      // we need to update it as well.
      //
      if ( tempNode == (*tail) )
      {
        (*tail) = newNode;
      }

      return;
    }
    else
    {
    tempNode = tempNode->next;
    }

  } while( tempNode != *head );

  printf("The value: %d is not in the list\n", data);
}


void printList( struct Node *head, struct Node *tail )
{
  struct Node *auxNode = head;

  printf( "--------------------------------------------------------------------\n" );

  do
  {
    printf( "%x:   { %d, %x, %x }\n", auxNode, auxNode->data, auxNode->prev, auxNode->next );

    auxNode = auxNode->next;
  } while ( auxNode != head );

  printf( "\n" );
  printf( "head = %x:   { %d, %x, %x }\n", head, head->data, head->prev, head->next );
  printf( "tail = %x:   { %d, %x, %x }\n", tail, tail->data, tail->prev, tail->next );
  printf( "--------------------------------------------------------------------\n" );
  printf( "\n\n" );

  return;
}

void printListReversed( struct Node *tail )
{
  struct Node *auxNode = tail;

  printf( "--------------------------------------------------------------------\n" );

  do
  {
    printf( "%x %d\n", auxNode, auxNode->data );

    auxNode = auxNode->prev;
  } while ( auxNode != tail );

  printf( "--------------------------------------------------------------------\n" );
  printf("\n");

  return;
}
