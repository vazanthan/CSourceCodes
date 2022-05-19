// Insert operation for linkedlist
#include<stdio.h>
#include<stdlib.h>

struct node *InsertNodeAshead (struct node *head, int item);
struct node *InsertNodeAsTail (struct node *head, int item);
struct node *InsetNodeAsInterim (struct node *head, int pos, int item);

struct node
{
  int data;
  struct node *next;
};


struct node *
InsertNodeAshead (struct node *head, int item)
{
  struct node *ptr = NULL, *qtr = NULL;
  qtr = head;

  ptr = (struct node *) malloc (sizeof (struct node));
  ptr->data = item;
  ptr->next = NULL;

  // Move the head address to ptr:-
  ptr->next = qtr;
  head = ptr;

  return head;
}

struct node *
InsertNodeAsTail (struct node *head, int item)
{

  struct node *ptr = NULL, *qtr = NULL;
  ptr = head;

  qtr = (struct node *) malloc (sizeof (struct node));
  qtr->data = item;
  qtr->next = NULL;

  while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }

  ptr->next = qtr;


  return head;
}


struct node *
InsetNodeAsInterim (struct node *head, int pos, int item)
{


  struct node *ptr = NULL, *qtr = NULL, *temp = NULL;
  int i;
  qtr = head;
  ptr = (struct node *) malloc (sizeof (struct node));
  ptr->data = item;
  ptr->next = NULL;

  for (i = 1; i < (pos - 1); i++)
    {
      qtr = qtr->next;
    }

  temp = qtr->next;
  qtr->next = ptr;
  ptr->next = temp;

  return head;
}

main ()
{
  int num_nodes = 0, item = 0, i, pos = 0;
  struct node *head = NULL, *ptr = NULL, *qtr = NULL;
  printf ("\t Enter the number of nodes in single linkedlist \n");
  scanf ("%d", &num_nodes);
  printf ("\t Enter the data for head node \n");
  scanf ("%d", &item);

  ptr = (struct node *) malloc (sizeof (struct node));
  ptr->data = item;
  ptr->next = NULL;

  head = ptr;

  for (i = 1; i < num_nodes; i++)
    {
      printf ("\t Enter the data for next node \n");
      scanf ("%d", &item);

      qtr = (struct node *) malloc (sizeof (struct node));
      qtr->data = item;
      qtr->next = NULL;

      // insert newly created node to previous node
      ptr->next = qtr;
      ptr = ptr->next;
    }

  // print the nodes of singlelinklist

  ptr = head;

  while (ptr != NULL)
    {
      printf ("\t The data in nodes of singlelinklist %d \n", ptr->data);
      ptr = ptr->next;
    }


  // insert nodes in linkedlist
  printf ("\t Enter the position, where you want to insert node \n");
  scanf ("%d", &pos);
  printf ("\t Enter the data for new node \n");
  scanf ("%d", &item);

  if ((pos > num_nodes + 2) || (pos < 1))
    {
      printf ("\t invalid Position ' exiting ' .... \n");
      exit (0);
    }


  if (pos == 1)
    {
      printf ("\t Inserting as Head node \n");
      head = InsertNodeAshead (head, item);
    }
  else if (pos == num_nodes + 1)
    {
      head = InsertNodeAsTail (head, item);
    }
  else
    {
      head = InsetNodeAsInterim (head, pos, item);
    }

  ptr = head;

  while (ptr != NULL)
    {
      printf ("\t The data in nodes after inserting in singlelinklist %d \n",
	      ptr->data);
      ptr = ptr->next;
    }


}

