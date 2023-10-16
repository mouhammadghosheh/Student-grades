#include <stdio.h>
#include "StudentList.h"
#include "GradesOperations.h"
int main() {
StudentList *NewList;
NewList = createList();
    ReadFile(NewList);
    printStudentList(NewList);
    Write(NewList);
    deleteList(NewList);
}


