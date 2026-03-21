#include "input_buffer.h"
#include "meta_command.h"
#include "statement.h"
#include "table.h"
#include <cstdio>

int main() {
    Table table;
    InputBuffer input_buffer;

    while (true) {
        input_buffer.print_prompt();
        input_buffer.read_input();
        const std::string& line = input_buffer.get_buffer();

        if (line.empty()) continue;

        // Meta‑commands start with '.'
        if (line[0] == '.') {
            switch (do_meta_command(line)) {
                case MetaCommandResult::SUCCESS:
                    continue;
                case MetaCommandResult::UNRECOGNIZED_COMMAND:
                    std::printf("Unrecognized command '%s'\n", line.c_str());
                    continue;
            }
        }

        Statement statement;
        PrepareResult prepare_result = prepare_statement(line, statement);
        switch (prepare_result) {
            case PrepareResult::SUCCESS:
                break;
            case PrepareResult::SYNTAX_ERROR:
                std::printf("Syntax error. Could not parse statement.\n");
                continue;
            case PrepareResult::UNRECOGNIZED_STATEMENT:
                std::printf("Unrecognized keyword at start of '%s'.\n", line.c_str());
                continue;
        }

        ExecuteResult exec_result = execute_statement(statement, table);
        switch (exec_result) {
            case ExecuteResult::SUCCESS:
                std::printf("Executed.\n");
                break;
            case ExecuteResult::TABLE_FULL:
                std::printf("Error: Table full.\n");
                break;
        }
    }

    return 0;
}