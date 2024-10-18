#pragma once

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 11
#define MAX_ENTRIES 100

// —труктура дл€ хранени€ данных о номерах и именах
struct NameAndPhoneNumber {
    char names[MAX_ENTRIES][MAX_NAME_LENGTH];
    int phones[MAX_ENTRIES][MAX_PHONE_LENGTH];
    int numberOfEntries;
};

// „итает данные, которые уже находились в файле, и добавл€ет их в структуру с номерами и именами
void readingFromAFile(struct NameAndPhoneNumber* records, const char* filename, bool* errorCode);

// ¬ыводит содержимое структуры с номерами и именами
void printAllAvailableRecords(struct NameAndPhoneNumber* records);