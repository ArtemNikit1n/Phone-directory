#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "workingWithAFile.h"

#define _CRT_SECURE_NO_WARNINGS

void saveToFile();

void readingFromAFile(struct NameAndPhoneNumber* records, const char *filename, bool *errorCode) {
    setlocale(LC_ALL, "Rus");

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("ќшибка открыти€ файла");
        *errorCode = true;
        return;
    }

    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH + 1];
    records->numberOfEntries = 0;

    while (fscanf(file, "%s Ч %s\n", name, phone) == 2) {
        strcpy(records->names[records->numberOfEntries], name);
        strcpy(records->phones[records->numberOfEntries], phone);
        records->numberOfEntries++;
    }

    fclose(file);
}

void printAllAvailableRecords(struct NameAndPhoneNumber *records) {
    for (int i = 0; i < records->numberOfEntries; ++i) {
        printf("%s Ч %s\n", records->names[i], records->phones[i]);
    }
}