#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

#include "workingWithAFile.h"

void outputOfReferenceInformation() {
    setlocale(LC_ALL, "Rus");
    printf("0 - выйти");
    printf("\n1 - добавить запись (имя и телефон)");
    printf("\n2 - распечатать все имеющиеся записи");
    printf("\n3 - найти телефон по имени");
    printf("\n4 - найти имя по телефону");
    printf("\n5 - сохранить текущие данные в файл\n");
}

short userInput(bool *errorCode) {
    outputOfReferenceInformation();

    char *strCommandNumber = (char *)calloc(10, sizeof(char));
    char *endptrCommandNumber = NULL;
    short commandNumber = -1;

    setlocale(LC_ALL, "Rus");

    if (strCommandNumber == NULL) {
        printf("Ошибка выделения памяти\n");
        *errorCode = true;
        return;
    }

    scanf("%s", strCommandNumber);
    commandNumber = (int)strtol(strCommandNumber, &endptrCommandNumber, 10);

    if (commandNumber < 0 || commandNumber > 6 || *endptrCommandNumber != '\0') {
        printf("Некорректный номер команды, попробуйте ещё раз\n");
        free(strCommandNumber);
        userInput(errorCode);
    } else {
        free(strCommandNumber);
        return commandNumber;
    }
}

void callingTheFunction(short commandNumber, bool *errorCode) {
    struct NameAndPhoneNumber records = {
    .numberOfEntries = 0,
    .names = { { '\0' } },
    .phones = { { '\0' } }
    };

    if (commandNumber == 0) {
        printf("Выход из справочника...\n");
        return;
    }
    else if (commandNumber == 1) {
        addANewContact(&records, &errorCode);
        short commandNumber = userInput(&errorCode);
        callingTheFunction(commandNumber, &errorCode);
    }
    else if (commandNumber == 2) {
        readingFromAFile(&records, "phoneDatabase.txt", &errorCode);
        printAllAvailableRecords(&records);
        short commandNumber = userInput(&errorCode) ;
        callingTheFunction(commandNumber, &errorCode);
    }
    else if (commandNumber == 3) {
        printf("Ещё не готово\n");
        short commandNumber = userInput(&errorCode);
        callingTheFunction(commandNumber, &errorCode);
    }
    else if (commandNumber == 4) {
        printf("Ещё не готово\n");
        short commandNumber = userInput(&errorCode);
        callingTheFunction(commandNumber, &errorCode);
    }
    else if (commandNumber == 5) {
        printf("Ещё не готово\n");
        short commandNumber = userInput(&errorCode);
        callingTheFunction(commandNumber, &errorCode);
    }
}

int main(void) {
    bool errorCode = false;
    //short commandNumber = userInput(&errorCode);

    //callingTheFunction(commandNumber, &errorCode);
    //while (errorCode) {
    //    callingTheFunction(commandNumber, &errorCode);
    //}
    printf("MYYAA");

    return errorCode;
}