#include "phone_book.h"



int main (int argc, char* args[])
{

phone_node *entry = NULL;
stack *s = NULL;
char a[30] ;
int number = 100;
int option = -1;
create_stack(&s, 1);/*create a stack is with size 1*/


do 
{
memset (a, '\0', 30);  
printf ("\n1)add a contact\n2)get a name from a number\n3)get a number from a name\n4)display whole stack\n5)remove an element\n6)sort the phonebook with char\n7)sort the phonebook with number\n8)purge the stack & exit\n");

while (!scanf ("%d",&option)) /*scanf but insure the user enters a interger not string, if user enters a string scanf will return 0 and then you simply flush \n from the stdin and wait for user to enter again*/
{

            printf("Please enter an integer value:\n");
                  while (getchar()!= '\n');
}

switch (option)

{

  case 1:
    {
printf ("enter the name\n");
scanf ("%30s",a); /*we use %30d since our array is of size 30 and we cannot accomodate string of longer length.NOTE:- you could ask for length of Name allocate memory and then ask user to enter the name, but seriously bruh if your name is more than 30 change it!*/
getchar(); /*remove \n from stdin of program*/
printf ("enter the number\n");
while (!scanf ("%d",&number))
{

            printf("Sorry only numbers allowed\n");
                  while (getchar()!= '\n');
}
entry = create_node (a, number);
push (s, entry);
break;
}
  case 2:
{
  printf ("enter the number\n");
while (!scanf ("%d",&number))
{

            printf("Sorry only numbers allowed\n");
                  while (getchar()!= '\n');
}
search_by_number(s,number);
break;
} 
case 3:
{
printf ("enter the name\n");
scanf ("%30s",a);
search_by_name(s,a);
break;
}
  case 4:
{
  print_stack(s);
break;
}
  case 5:
{
  printf ("enter the number\n");
while (!scanf ("%d",&number))
{

            printf("Sorry only numbers allowed\n");
                  while (getchar()!= '\n');
}
delete_by_number(s,number);
break;
} 
case 6:
{ 
sort_by_name(s);
printf ("finished sorting by name\n");
 break;
  case 7:
 sort_by_number(s);
 printf ("finished sorting by number");
   break;
}
  case 8:
{
  destroy_stack(&s, s->size);
exit (0);
break;
}
  default :
    printf ("please enter a proper option\n");
break;
}


}while (8 != option); /*basically iterate until 8 is encontered*/




return FAILURE;
}
