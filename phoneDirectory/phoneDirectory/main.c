#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
//#include <windows.h>
#include <assert.h>

#include "workingWithAFile.h"

void outputOfReferenceInformation(void) {
    setlocale(LC_ALL, "Rus");
    printf("\n------------------");
    printf("\nГлавное меню:");
    printf("\n0 - выйти");
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

    assert(strCommandNumber != NULL);

    printf("\nВведите команду: ");
    scanf("%s", strCommandNumber);
    commandNumber = (short)strtol(strCommandNumber, &endptrCommandNumber, 10);

    if (commandNumber < 0 || commandNumber > 6 || *endptrCommandNumber != '\0') {
        printf("\nНекорректный номер команды, попробуйте ещё раз\n");
        free(strCommandNumber);
        userInput(errorCode);
    } else {
        free(strCommandNumber);
        return commandNumber;
    }
}

void callingTheFunction(struct NameAndPhoneNumber* records, short commandNumber, bool *errorCode) {
    if (commandNumber == 0) {
        printf("Выход из справочника...\n");
        return;
    }
    else if (commandNumber == 1) {
        printf("\nДобавление записи\n\n");
        addANewContact(records, errorCode);
        commandNumber = userInput(errorCode);
        callingTheFunction(records, commandNumber, errorCode);
    }
    else if (commandNumber == 2) {
        printAllAvailableRecords(records);
        commandNumber = userInput(errorCode) ;
        callingTheFunction(records, commandNumber, errorCode);
    }
    else if (commandNumber == 3) {
        printf("Ещё не готово\n");
        commandNumber = userInput(errorCode);
        callingTheFunction(records, commandNumber, errorCode);
    }
    else if (commandNumber == 4) {
        printf("Ещё не готово\n");
        commandNumber = userInput(errorCode);
        callingTheFunction(records, commandNumber, errorCode);
    }
    else if (commandNumber == 5) {
        saveToFile(records, "phoneDatabase.txt");
        commandNumber = userInput(errorCode);
        callingTheFunction(records, commandNumber, errorCode);
    }
}

int main(void) {
    setlocale(LC_ALL, "Rus");
    //SetConsoleOutputCP(CP_UTF8);

    bool errorCode = false;
    short commandNumber = userInput(&errorCode);
    struct NameAndPhoneNumber records = {
        .numberOfEntries = 0,
        .names = { { '\0' } },
        .phones = { { '\0' } }
    };

    readingFromAFile(&records, "phoneDatabase.txt");
    callingTheFunction(&records, commandNumber, &errorCode);
    while (errorCode) {
        callingTheFunction(&records, commandNumber, &errorCode);
    }

    return errorCode;
}