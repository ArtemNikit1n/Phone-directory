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

    printf("������� ��� ������ ��������:\n");
    scanf("%s", &name);
    if (strlen(name) == sizeof(name) - 1) {
        printf("������� ����� �������� � �����, ���������� ��� ���\n");
        *errorCode = true;
        return;
    }

    printf("������� ����� ��������:\n");
    scanf("%s", &phone);
    if (strlen(name) == sizeof(name) - 1) {
        printf("������� ����� �������� � ������ ��������\n");
        *errorCode = true;
        return;
    }

    printf("��������� ��������� �� ������� ���������� � ��������:\n%s � %s\n", name, phone);
    printf("0 � � ���� ������ ���������\n1 � �� �����\n");
    if (contactAdded = false) {
        addANewContact(records, errorCode);
    }
}

void readingFromAFile(struct NameAndPhoneNumber* records, const char *filename, bool *errorCode) {
    setlocale(LC_ALL, "Rus");

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("������ �������� �����");
        *errorCode = true;
        return;
    }

    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    records->numberOfEntries = 0;

    while (fscanf(file, "%s � %s\n", name, phone) == 2) {
        strcpy(records->names[records->numberOfEntries], name);
        strcpy(records->phones[records->numberOfEntries], phone);
        records->numberOfEntries++;
    }
    fclose(file);
}

void printAllAvailableRecords(struct NameAndPhoneNumber *records) {
    for (int i = 0; i < records->numberOfEntries; ++i) {
        printf("%s � %s\n", records->names[i], records->phones[i]);
    }
}