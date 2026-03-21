#include "table.h"
#include <cstdlib>

Table::Table() : num_rows_(0) {
    for (auto& page : pages_) page = nullptr;
}

Table::~Table() {
    for (auto page : pages_) {
        if (page) free(page);
    }
}

void* Table::row_slot(uint32_t row_num) {
    uint32_t page_num = row_num / ROWS_PER_PAGE;
    void* page = pages_[page_num];
    if (!page) {
        page = pages_[page_num] = malloc(PAGE_SIZE);
    }
    uint32_t row_offset = row_num % ROWS_PER_PAGE;
    uint32_t byte_offset = row_offset * ROW_SIZE;
    return static_cast<char*>(page) + byte_offset;
}

ExecuteResult Table::insert(const Row& row) {
    if (num_rows_ >= TABLE_MAX_ROWS) {
        return ExecuteResult::TABLE_FULL;
    }
    serialize_row(row, row_slot(num_rows_));
    ++num_rows_;
    return ExecuteResult::SUCCESS;
}

ExecuteResult Table::select() {
    Row row;
    for (uint32_t i = 0; i < num_rows_; ++i) {
        deserialize_row(row_slot(i), row);
        print_row(row);
    }
    return ExecuteResult::SUCCESS;
}