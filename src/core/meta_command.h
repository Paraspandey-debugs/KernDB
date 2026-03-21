#ifndef META_COMMAND_H
#define META_COMMAND_H

#include <string>

enum class MetaCommandResult {
    SUCCESS,
    UNRECOGNIZED_COMMAND
};

MetaCommandResult do_meta_command(const std::string& command);

#endif // META_COMMAND_H