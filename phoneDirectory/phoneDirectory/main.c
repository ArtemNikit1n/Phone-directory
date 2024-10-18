#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

void outputOfReferenceInformation() {
    setlocale(LC_ALL, "Rus");
    printf("0 - выйти");
    printf("\n1 - добавить запись (имя и телефон)");
    printf("\n2 - распечатать все имеющиеся записи");
    printf("\n3 - найти телефон по имени");
    printf("\n4 - найти имя по телефону");
    printf("\n5 - сохранить текущие данные в файл\n");
}

void userInput(short *commandNumber, bool *errorCode) {
    char *strCommandNumber = (char *)calloc(10, sizeof(char));
    char *endptrCommandNumber = NULL;

    setlocale(LC_ALL, "Rus");

    if (strCommandNumber == NULL) {
        printf("Ошибка выделения памяти\n");
        *errorCode = true;
        return;
    }

    scanf("%s", strCommandNumber);
    *commandNumber = (int)strtol(strCommandNumber, &endptrCommandNumber, 10);

    if (*commandNumber < 0 || *commandNumber > 6 || *endptrCommandNumber != '\0') {
        *commandNumber = -1;
        printf("Некорректный номер команды, попробуйте ещё раз\n");
        outputOfReferenceInformation();
    }
    free(strCommandNumber);
}

void callingTheFunction(short *commandNumber, bool* errorCode) {
    if (*commandNumber == 1) {
        printf("1\n");
    }
    else if (*commandNumber == 2) {
        printf("2\n");
    }
    else if (*commandNumber == 3) {
        printf("3\n");
    }
    else if (*commandNumber == 4) {
        printf("4\n");
    }
    else if (*commandNumber == 5) {
        printf("5\n");
    }
}

int main(void) {
    bool errorCode = false;
    short commandNumber = -1;

    outputOfReferenceInformation();
    while ((commandNumber < 0 || commandNumber > 6) && errorCode == false) {
        userInput(&commandNumber, &errorCode);
    }
    callingTheModule(&commandNumber, &errorCode);
    printf("%d", commandNumber);

    return errorCode;
}