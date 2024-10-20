#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
//#include <windows.h>
#include <string.h>
#include <assert.h>

#include "workingWithAFile.h"

void saveToFile(struct NameAndPhoneNumber* records, const char* filename) {
    FILE* file = fopen(filename, "w");
    assert(file != NULL);

    if (records->numberOfEntries == 0) {
        printf("\n�� ������� ������ ������ �����������\n");
        return;
    }
    for (int i = 0; i < records->numberOfEntries; ++i) {
        fprintf(file, "%s - %s\n", records->names[i], records->phones[i]);
    }
    printf("\n�������� ������� ��������� � ����\n");
}

void addANewContact(struct NameAndPhoneNumber* records) {
    char name[MAX_NAME_LENGTH] = { "\0" };
    char phone[MAX_PHONE_LENGTH] = { "\0" };
    bool theInputIsSuccessful = false;
    bool contactAdded = false;

    printf("������� ��� ������ ��������:\n");
    getchar();
    fscanf(stdin, "%s", name);
    if (strlen(name) >= MAX_NAME_LENGTH - 1) {
        printf("������� ����� �������� � �����, ���������� ��� ���\n");
        addANewContact(records);
        return;
    }

    printf("������� ����� ��������:\n");
    getchar();
    fscanf(stdin, "%s", phone);
    if (strlen(phone) >= MAX_PHONE_LENGTH - 1) {
        printf("������� ����� �������� � ������ ��������, ���������� ��� ���\n");
        addANewContact(records);
        return;
    }

    printf("��������� ��������� �� ������� ���������� � ��������\n%s - %s\n", name, phone);
    printf("0 - � ���� ������ ���������\n1 - �� �����\n");
    while (!theInputIsSuccessful) {
        char input[5];
        scanf("%s", &input);
        if (input[0] == '1' && input[1] == '\0') {
            theInputIsSuccessful = true;
            contactAdded = true;
        }
        else if (input[0] == '0' && input[1] == '\0') {
            theInputIsSuccessful = true;
            contactAdded = false;
        }
        else {
            theInputIsSuccessful = false;
            printf("�������� ����. ������� 1 ��� 0.\n");
        }
    }

    if (contactAdded == false) {
        addANewContact(records);
    } else {
        strcpy(records->names[records->numberOfEntries], name);
        strcpy(records->phones[records->numberOfEntries], phone);
        records->numberOfEntries++;
        printf("������� ������!\n");
        return;
    }
}

void readingFromAFile(struct NameAndPhoneNumber* records, const char *filename) {
    FILE* file = fopen(filename, "r");
    assert(file != NULL);

    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    records->numberOfEntries = 0;

    while (fscanf(file, "%s - %s\n", name, phone) == 2) { 
        strcpy(records->names[records->numberOfEntries], name);
        strcpy(records->phones[records->numberOfEntries], phone);
        records->numberOfEntries++;
    }
    fclose(file);
}

void searchByName(struct NameAndPhoneNumber* records) {
    char name[MAX_NAME_LENGTH] = {"\0"};
    bool thePhoneWasFound = false;

    printf("\n������� ��� �������� ��������:\n\n");
    getchar();
    fscanf(stdin, "%s", name);
    if (strlen(name) >= MAX_NAME_LENGTH - 1) {
        printf("������� ����� �������� � �����, ���������� ��� ���\n");
        searchByName(records);
        return;
    }

    for (int i = 0; i < records->numberOfEntries; ++i) {
        if (strcmp(&name, &records->names[i]) == 0) {
            printf("%s\n", records->phones[i]);
            thePhoneWasFound = true;
        }
    }
    if (!thePhoneWasFound) {
        printf("������� �� ������\n");
    }
}

void searchByPhone(struct NameAndPhoneNumber* records) {
    char phone[MAX_PHONE_LENGTH] = { "\0" };
    bool theNameWasFound = false;

    printf("\n������� ������� �������� ��������:\n\n");
    getchar();
    fscanf(stdin, "%s", phone);
    if (strlen(phone) >= MAX_NAME_LENGTH - 1) {
        printf("������� ������� ����� ��������, ���������� ��� ���\n");
        searchByPhone(records);
        return;
    }

    for (int i = 0; i < records->numberOfEntries; ++i) {
        if (strcmp(&phone, &records->phones[i]) == 0) {
            printf("%s\n", records->names[i]);
            theNameWasFound = true;
        }
    }
    if (!theNameWasFound) {
        printf("��� �� �������\n");
    }
}

void printAllAvailableRecords(struct NameAndPhoneNumber *records) {
    if (records->numberOfEntries == 0) {
        printf("\n�� ������� ������ ������ �����������\n");
        return;
    }
    printf("\n������� ������ (� ��� ����� �� ������������ � �����):\n\n");
    for (int i = 0; i < records->numberOfEntries; ++i) {
        printf("%d. %s - %s\n", i + 1, records->names[i], records->phones[i]);
    }
    printf("\n* ��� ���������� ���� ������ ������� 5\n");
}