#pragma once

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 11
#define MAX_ENTRIES 100

// ��������� ��� �������� ������ � ������� � ������
struct NameAndPhoneNumber {
    char names[MAX_ENTRIES][MAX_NAME_LENGTH];
    int phones[MAX_ENTRIES][MAX_PHONE_LENGTH];
    int numberOfEntries;
};

// ������ ������, ������� ��� ���������� � �����, � ��������� �� � ��������� � �������� � �������
void readingFromAFile(struct NameAndPhoneNumber* records, const char* filename, bool* errorCode);

// ������� ���������� ��������� � �������� � �������
void printAllAvailableRecords(struct NameAndPhoneNumber* records);