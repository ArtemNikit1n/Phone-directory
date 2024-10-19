#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "workingWithAFile.h"

void saveToFile();

void addANewContact(struct NameAndPhoneNumber* records, bool *errorCode) {
    setlocale(LC_ALL, "Rus");
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    bool contactAdded = false;

    printf("¬ведите им€ нового контакта:\n");
    scanf("%s", &name);
    if (strlen(name) == sizeof(name) - 1) {
        printf("—лишком много символов в имени, попробуйте ещЄ раз\n");
        *errorCode = true;
        return;
    }

    printf("¬ведите номер телефона:\n");
    scanf("%s", &phone);
    if (strlen(name) == sizeof(name) - 1) {
        printf("—лишком много символов в номере телефона\n");
        *errorCode = true;
        return;
    }

    printf("ѕроверьте правильно ли введена информаци€ о контакте:\n%s Ч %s\n", name, phone);
    printf("0 Ч я хочу внести изменени€\n1 Ч ¬сЄ верно\n");
    if (contactAdded = false) {
        addANewContact(records, errorCode);
    }
}

void readingFromAFile(struct NameAndPhoneNumber* records, const char *filename, bool *errorCode) {
    setlocale(LC_ALL, "Rus");

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("ќшибка открыти€ файла");
        *errorCode = true;
        return;
    }

    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
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