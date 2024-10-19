#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_ENTRIES 100

// Структура для хранения данных о номерах и именах
struct NameAndPhoneNumber {
    char names[MAX_ENTRIES][MAX_NAME_LENGTH];
    int phones[MAX_ENTRIES][MAX_PHONE_LENGTH];
    int numberOfEntries;
};

// Добавляет имя и телефон в структуру NameAndPhoneNumber
void addANewContact(struct NameAndPhoneNumber* records, bool* errorCode);

// Читает данные, которые уже находились в файле, и добавляет их в структуру NameAndPhoneNumber
void readingFromAFile(struct NameAndPhoneNumber* records, const char* filename, bool* errorCode);

// Выводит содержимое структуры NameAndPhoneNumber с номерами и именами
void printAllAvailableRecords(struct NameAndPhoneNumber* records);