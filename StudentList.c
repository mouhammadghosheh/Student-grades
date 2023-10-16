#include "StudentList.h"
#include <stdio.h>
#include <stdlib.h>


StudentList* createList(){
StudentList *List;
    List = (StudentList*)malloc(sizeof(StudentList));
    List -> head = NULL;
    return List;
}
void deleteList(StudentList* List){
    free(List);
    free(List->head);
    free(List->head->st);
    List->head->st = NULL;
    List->head = NULL;
    List = NULL;
}
void printStudentNode(StudentNode* const studentNode){
    printf("%d  %d  %d\n", studentNode -> st -> id, studentNode -> st ->grade1, studentNode -> st ->grade2);
}
void printStudentList(StudentList* const List){
    StudentNode *p;


    p = List -> head;
while(p!=NULL){
    printStudentNode(p);
    p = p->next;
}
}
void addToList(StudentList* List, Student* student){

    StudentNode *p;
    StudentNode *NewStudent;
    NewStudent = (StudentNode*) malloc(sizeof (StudentNode));
    NewStudent -> st = student;


    if(List -> head == NULL){
        List -> head = NewStudent;
        List -> head -> next = NULL;
    }



    else {
    for (p= List->head; p -> next != NULL; p = p->next);
    p -> next = NewStudent;
    p -> next ->next = NULL;

    }




}