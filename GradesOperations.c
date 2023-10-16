

#include <stdlib.h>
#include "StudentList.h"
#include "GradesOperations.h"

const int INT_MAX = 2147483647; 
void ReadFile(StudentList* NewList){  //The file reading function

    StudentNode *NewStudent;
    NewStudent = (StudentNode*) malloc(sizeof (StudentNode));
    NewStudent -> st = (Student*) malloc(sizeof (Student));
    FILE *F;
    F = fopen("StudentsGrades.txt", "r");
    if(F == NULL)
        exit(0);

while(!feof(F)){

    fscanf(F, "%d %d %d", &NewStudent->st->id, &NewStudent->st->grade1, &NewStudent->st->grade2);

        addToList(NewList,NewStudent->st);

    NewStudent = (StudentNode*) malloc(sizeof (StudentNode));
    NewStudent -> st = (Student*) malloc(sizeof (Student));

   }
    fclose(F);
}


int StudentNumber(StudentList* const NewList) { //Number of students

    StudentNode *p;

    int counter = 0;
    p = NewList->head;
    while (p != NULL) {
        counter++;
        p = p->next;
    }
    return counter;
}

    int OnlyOneTestStudents(StudentList* const NewList){ //students that only tested once
        StudentNode *p;

        int counter = 0;
        p = NewList->head;

        while (p != NULL) {
           if((p ->st->grade1 == -1 && p->st->grade2!=-1)|| (p->st->grade2 == -1 && p->st->grade1!=-1))
               counter++;
            p = p->next;
        }
        return counter;
    }

int NoTestStudents(StudentList* const NewList){ //students that didn't test
    StudentNode *p;

    int counter = 0;
    p = NewList->head;

    while (p != NULL) {
        if(p ->st->grade1 == -1&&p->st->grade2 == -1)
            counter++;
        p = p->next;
    }
    return counter;
}


double Failures(StudentList* const NewList){    //Students that failed in the first exam
    StudentNode *p;
    double percent;
    double counter = 0;
    p = NewList->head;

    while (p != NULL) {
        if(p->st->grade1!=-1){
        if(p ->st->grade1 < 60)
            counter++;

    }p = p->next;
    }
    percent = counter/ StudentNumber(NewList);
    return percent*100;
}

double FailuresInBet(StudentList* const NewList){   //Students that failed in the Second exam
    StudentNode *p;
    double percent;
    double counter = 0;
    p = NewList->head;

    while (p != NULL) {
        if(p->st->grade2!=-1){
            if(p ->st->grade2 < 60)
                counter++;

        }p = p->next;
    }
    percent = counter/ StudentNumber(NewList);
    return percent*100;
}


double Median(StudentList* const NewList){  //the class Median in the first exam
    StudentNode *p;
    double percent;
   double sum = 0;
    double counter = 0;
    p = NewList->head;

    while (p != NULL) {
        if(p->st->grade1==-1)
            counter++;
        else
            sum += p->st->grade1;
        p = p->next;
    }
    percent = sum / (StudentNumber(NewList) - counter);
    return percent;
}

double MedianBet(StudentList* const NewList){ //the class Median in the second exam
    StudentNode *p;
    double percent;
    double sum = 0;
    double counter = 0;
    p = NewList->head;

    while (p != NULL) {
        if(p->st->grade2==-1)
            counter++;
        else
            sum += p->st->grade2;
        p = p->next;
    }
    percent = sum / (StudentNumber(NewList) - counter);
    return percent;
}


int MaxGrade(StudentList* const NewList){       //the maximum grade
    StudentNode *p;
    p = NewList->head;
    int max = 0;
    int FirstPlace;
    while (p != NULL) {
        if(p->st->grade1 >= p->st->grade2) {
            if (p->st->grade1 > max) {
                max = p->st->grade1;
                FirstPlace = p->st->id;
            }
        }
        else{
            if (p->st->grade2 > max) {
                max = p->st->grade2;
                FirstPlace = p->st->id;
            }
        }
        p = p->next;
    }
    return FirstPlace;
}

int MinGrade(StudentList* const NewList){   //the minimum grade
    StudentNode *p;
    p = NewList->head;
    int min = INT_MAX;
    int LastPLace;
    while (p != NULL) {
        if( p->st->grade1 != -1 || p->st->grade2 != -1){

                if((p->st->grade1 <= p->st->grade2 || p->st->grade2 == -1)&&(p->st->grade1 != -1)) {
            if (p->st->grade1 < min) {
                min = p->st->grade1;
                LastPLace = p->st->id;
            }
        }
        else{
            if(p->st->grade1 == -1)
            if (p->st->grade2 < min) {
                min  = p->st->grade2;
                LastPLace = p->st->id;
            }
        }}
        p = p->next;
    }
    return LastPLace;
}


void Write(StudentList* const NewList){ //function that creates and writes into the report.txt file
    FILE* fp;

    fp = fopen("Report.txt","w");
    if(fp == NULL)
        exit(0);


        fprintf(fp, "Number of Students: %d\n"
                            "Number of students that only tested once: %d\n"
                            "Number of students that didn't test: %d\n"
                            "Percentage of failures in Test A: %.2f%%\n"
                            "Percentage of failures in Test B: %.2f%%\n"
                            "The Median in Test A: %.2f\n"
                            "The Median in Test B: %.2f\n"
                            "The highest grade is for the student with id Number: %d\n"
                            "The Lowest grade is for the student with id Number: %d\n", StudentNumber(NewList),
                                                                                        OnlyOneTestStudents(NewList),
                                                                                        NoTestStudents(NewList),
                                                                                        Failures(NewList),
                                                                                        FailuresInBet(NewList),
                                                                                        Median(NewList),
                                                                                        MedianBet(NewList),
                                                                                        MaxGrade(NewList),
                                                                                        MinGrade(NewList));
    fclose(fp);

}