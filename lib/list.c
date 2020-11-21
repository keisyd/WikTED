#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>
#include "list.h"

List* insertList(char** params, int size, List* popList)
{
   printf("\ninserting %s\n", params[0]);
   //creating a new list  
   List* list = (List*)malloc(sizeof(List));

   list->name = (char **)malloc(sizeof(char *)*(size));

   for(int j = 0; j<size; j++)
   {
      list->name[j] = (char *)malloc(sizeof(char)*( (strlen(params[j])+10) ));

      strcpy((list->name)[j],params[j]);

      printf("[%d]: %s ",j, (list->name)[j] ); 
   }

   list->next = popList;
   list->reference = NULL;

   return list;
}


void printList(List* popList, int size) 
{
   printf("\n<p>\n");

   struct List *list = popList;
	
   //start from the beginning
    while(list != NULL) 
    {   
       printf("\n");
        for(int j = 0; j<size; j++)
        {
            printf("[%d] : %s ",j, (list->name)[j]);
        }
        if(list->reference != NULL) if(list->reference->name != NULL) printf("\n ref: %s",list->reference->name[0] );
        list = list->next;
    }
}

List* deleteList(char name[], List* popList)
{
   printf("deliting %s... \n", name);
   struct List* currentList = popList; //taking the last inserted
   struct List* previous = NULL;
   

   if(popList == NULL) {
      //if none was inserted yet, there's nothing to be deleted
      printf("Nothing to be delete");
      return popList;
      //todo: create a log (logfile) for this
   }
   //todo: Free the linked lists first
   //searching for the page name
   while(strcmp(currentList->name[0], name)!=0) {

      printf("s %s\n",currentList->name[0]);
      if(currentList->next == NULL) {
         printf("Name not found");
         //todo: create a log (logfile) for this

         return popList;//if null was found, that's the end of the page
      } else {//if there're some items
         previous = currentList;//keep the previous 
         currentList = currentList->next;//and look for the name in the next one
      }  
   }
   
   if(currentList == popList) {//in case it's the last inserted
      popList = popList->next;//just point it to the next
   } else {//otherwise
      previous->next = currentList->next;//make the previous point to the next one
   }
   free(currentList);
   return popList;
}

List* findListByName(List* popList, char name[])
{
   struct List* currentList = popList; //taking the last inserted
   struct List* previous = NULL;
   
   if(popList == NULL) {
      return NULL;//if none was inserted yet, there's nothing to be deleted
      //todo: create a log (logfile) for this
   }
   //todo: Free the linked lists first
   //searching for the page name
   while(strcmp(currentList->name[0], name)!=0) {
      
      if(currentList->next == NULL) {
         printf("\nName not found\n");
         //todo: create a log (logfile) for this
         return NULL;//if null was found, that's the end of the page
      } else {//if there're some items
         previous = currentList;//keep the previous 
         currentList = currentList->next;//and look for the name in the next one
      }  
   }
   return currentList;

}