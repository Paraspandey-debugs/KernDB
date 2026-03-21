#ifndef STATEMENT_H
#define STATEMENT_H

#include "table.h"
#include <string>

enum class StatementType {
    INSERT,
    SELECT
};

struct Statement {
    StatementType type;
    Row row_to_insert;   // only used for INSERT
};

enum class PrepareResult {
    SUCCESS,
    SYNTAX_ERROR,
    UNRECOGNIZED_STATEMENT
};

PrepareResult prepare_statement(const std::string& input, Statement& statement);
ExecuteResult execute_statement(const Statement& statement, Table& table);

#endif // STATEMENT_H