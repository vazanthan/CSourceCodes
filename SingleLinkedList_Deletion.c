//Deletion functionality in singlelinklist
#include<stdio.h>
#include<stdlib.h>

struct node *DeleteHeadNode (struct node *head);
struct node *DeleteTailNode (struct node *head);
struct node *DeleteInterimNode (struct node *head, int pos);


struct node
{
  int data;
  struct node *next;
};

struct node *
DeleteHeadNode (struct node *head)
{

  struct node *ptr;
  ptr = head;

  head = ptr->next;
  free (ptr);

  return head;
}

struct node *
DeleteTailNode (struct node *head)
{
  struct node *ptr = NULL, *temp = NULL;
  ptr = head;

  while (ptr->next != NULL)
    {
      ptr = ptr->next;

      temp = ptr->next;
      free (temp);
      ptr->next = NULL;
    }


  return head;
}

struct node *
DeleteInterimNode (struct node *head, int pos)
{

  int i;
  struct node *ptr = NULL, *temp = NULL;
  ptr = head;

  for (i = 1; i < (pos - 1); i++)
    {
      ptr = ptr->next;
    }

  temp = ptr->next;
  ptr->next = temp->next;
  free (temp);

  return head;
}

main ()
{
  int num_nodes = 0, item = 0, i, pos = 0;
  struct node *head = NULL, *ptr = NULL, *qtr = NULL;
  printf ("\t Enter the number of nodes in singlelinklist \n");
  scanf ("%d", &num_nodes);
  printf ("\t Enter the data for HEAD node in singlelinklist \n");
  scanf ("%d", &item);

  ptr = (struct node *) malloc (sizeof (struct node));
  ptr->data = item;
  ptr->next = NULL;

  head = ptr;

  for (i = 1; i < num_nodes; i++)
    {
      printf ("\t Enter the data for other node in singlelinklist \n");
      scanf ("%d", &item);

      qtr = (struct node *) malloc (sizeof (struct node));
      qtr->data = item;
      qtr->next = NULL;
      // insert new node  to previous nodes in singlelinklist
      ptr->next = qtr;
      ptr = ptr->next;
    }

  // print the data in singlelinklist

  ptr = head;

  while (ptr != NULL)
    {
      printf (" \t The data in nodes of singlelinklist %d \n", ptr->data);
      ptr = ptr->next;
    }

  // Delete the nodes in singlelinklist

  printf
    (" \t Enter the position, where you want to delete the node in singlelinklist \n");
  scanf ("%d", &pos);
  if ((pos < 1) || (pos > num_nodes))
    {
      printf (" \t Invalid position \n");
      exit (0);
    }

  if (pos == 1)
    {
      head = DeleteHeadNode (head);
    }
  else if (pos == num_nodes)
    {
      head = DeleteTailNode (head);
    }
  else
    {
      head = DeleteInterimNode (head, pos);
    }

  // print the data in singlelinklist after deletion

  ptr = head;

  while (ptr != NULL)
    {
      printf (" \t The data in nodes of singlelinklist %d \n", ptr->data);
      ptr = ptr->next;
    }
}
