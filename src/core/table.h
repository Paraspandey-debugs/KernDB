#ifndef TABLE_H
#define TABLE_H

#include "row.h"
#include <cstdint>

const uint32_t PAGE_SIZE = 4096;
const uint32_t TABLE_MAX_PAGES = 100;
const uint32_t ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
const uint32_t TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;

enum class ExecuteResult {
    SUCCESS,
    TABLE_FULL
};

class Table {
public:
    Table();
    ~Table();

    ExecuteResult insert(const Row& row);
    ExecuteResult select();   // prints all rows

private:
    uint32_t num_rows_;
    void* pages_[TABLE_MAX_PAGES];

    void* row_slot(uint32_t row_num);
};

#endif // TABLE_H