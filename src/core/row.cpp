#include "row.h"
#include <cstdio>

void serialize_row(const Row& source, void* destination) {
    memcpy(static_cast<char*>(destination) + ID_OFFSET, &source.id, ID_SIZE);
    memcpy(static_cast<char*>(destination) + USERNAME_OFFSET, &source.username, USERNAME_SIZE);
    memcpy(static_cast<char*>(destination) + EMAIL_OFFSET, &source.email, EMAIL_SIZE);
}

void deserialize_row(const void* source, Row& destination) {
    memcpy(&destination.id, static_cast<const char*>(source) + ID_OFFSET, ID_SIZE);
    memcpy(&destination.username, static_cast<const char*>(source) + USERNAME_OFFSET, USERNAME_SIZE);
    memcpy(&destination.email, static_cast<const char*>(source) + EMAIL_OFFSET, EMAIL_SIZE);
}

void print_row(const Row& row) {
    printf("(%d, %s, %s)\n", row.id, row.username, row.email);
}