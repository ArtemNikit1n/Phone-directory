#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_ENTRIES 100

// ��������� ��� �������� ������ � ������� � ������
struct NameAndPhoneNumber {
    char names[MAX_ENTRIES][MAX_NAME_LENGTH];
    int phones[MAX_ENTRIES][MAX_PHONE_LENGTH];
    int numberOfEntries;
};

// ��������� ��� � ������� � ��������� NameAndPhoneNumber
void addANewContact(struct NameAndPhoneNumber* records);

// ������ ������, ������� ��� ���������� � �����, � ��������� �� � ��������� NameAndPhoneNumber
void readingFromAFile(struct NameAndPhoneNumber* records, const char *filename);

// ������� ���������� ��������� NameAndPhoneNumber � �������� � �������
void printAllAvailableRecords(struct NameAndPhoneNumber* records);

// ����� �������� � ���������
void searchByName(struct NameAndPhoneNumber* records);

// ����� ����� � ���������
void searchByPhone(struct NameAndPhoneNumber* records);

// ������� ��� ���������� ������ �� ��������� � ����
void saveToFile(struct NameAndPhoneNumber* records, const char *filename);