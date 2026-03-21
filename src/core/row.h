#ifndef ROW_H
#define ROW_H

#include <cstdint>
#include <cstring>

const uint32_t COLUMN_USERNAME_SIZE = 32;
const uint32_t COLUMN_EMAIL_SIZE = 255;

struct Row {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE];
    char email[COLUMN_EMAIL_SIZE];
};

// Offsets and sizes (could be static member functions, but we'll use simple constants)
const uint32_t ID_SIZE = sizeof(((Row*)0)->id);
const uint32_t USERNAME_SIZE = sizeof(((Row*)0)->username);
const uint32_t EMAIL_SIZE = sizeof(((Row*)0)->email);
const uint32_t ID_OFFSET = 0;
const uint32_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
const uint32_t EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;
const uint32_t ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;

void serialize_row(const Row& source, void* destination);
void deserialize_row(const void* source, Row& destination);
void print_row(const Row& row);

#endif // ROW_H