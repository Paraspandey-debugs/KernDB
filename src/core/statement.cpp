#include "statement.h"
#include <cstdio>
#include <algorithm>
#include <cctype>

static std::string to_upper(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return result;
}

PrepareResult prepare_statement(const std::string& input, Statement& statement) {
    std::string upper = to_upper(input);

    if (upper.rfind("INSERT", 0) == 0) {
        statement.type = StatementType::INSERT;
        // Parse the rest: INSERT id username email
        int args = sscanf(input.c_str(), "INSERT %u %31s %254s",
                          &statement.row_to_insert.id,
                          statement.row_to_insert.username,
                          statement.row_to_insert.email);
        if (args != 3) {
            return PrepareResult::SYNTAX_ERROR;
        }
        return PrepareResult::SUCCESS;
    }

    if (upper.rfind("SELECT", 0) == 0) {
        statement.type = StatementType::SELECT;
        return PrepareResult::SUCCESS;
    }

    return PrepareResult::UNRECOGNIZED_STATEMENT;
}

ExecuteResult execute_statement(const Statement& statement, Table& table) {
    switch (statement.type) {
        case StatementType::INSERT:
            return table.insert(statement.row_to_insert);
        case StatementType::SELECT:
            return table.select();
    }
    // unreachable
    return ExecuteResult::SUCCESS;
}