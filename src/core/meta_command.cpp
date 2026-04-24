#include "meta_command.h"
#include <cstdlib>
#include <cstring>

MetaCommandResult do_meta_command(const std::string& command) {
    if (command == ".exit") {
        std::exit(EXIT_SUCCESS);
    } else {
        return MetaCommandResult::UNRECOGNIZED_COMMAND;
    }
}