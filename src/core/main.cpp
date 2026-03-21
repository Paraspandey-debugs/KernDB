#include <iostream>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <algorithm>
#include <cctype>

typedef struct {
    std::string buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;

typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
  StatementType type;
} Statement;

void print_prompt() { printf("db > "); }

InputBuffer* new_input_buffer() {
    InputBuffer* input_buffer = new InputBuffer;
    input_buffer->buffer = "";
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;
    return input_buffer;
}

void read_input(InputBuffer* input_buffer) {
    if(!std::getline(std::cin, input_buffer->buffer)){
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }

    input_buffer->input_length = input_buffer->buffer.size();
    input_buffer->buffer_length = input_buffer->buffer.capacity();
}

void close_input_buffer(InputBuffer* input_buffer) {
    delete input_buffer;
}


MetaCommandResult do_meta_command(InputBuffer* input_buffer){
    if(input_buffer->buffer == ".exit"){
        exit(EXIT_SUCCESS);
    }else{
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

PrepareResult prepare_statement(InputBuffer* input_buffer,Statement* statement){

    std::string input = input_buffer->buffer;

    // convert to uppercase
    std::transform(input.begin(), input.end(), input.begin(),
                [](unsigned char c) { return std::toupper(c); });

    if (input.rfind("INSERT", 0) == 0) {
        return PREPARE_SUCCESS;
    }

    if (input.rfind("SELECT", 0) == 0) {
        return PREPARE_SUCCESS;
    }
        return PREPARE_UNRECOGNIZED_STATEMENT;

}
void execute_statement(Statement* statement){

}
int main(int argc , char* argv[]){
    InputBuffer* input_buffer = new_input_buffer();
    
    while(true){
        print_prompt();
        read_input(input_buffer);
        if(input_buffer->buffer[0] == '.'){
            switch (do_meta_command(input_buffer)){
                case (META_COMMAND_SUCCESS):
                    continue;
                case (META_COMMAND_UNRECOGNIZED_COMMAND):
                    printf("Unrecognized command '%s\n",input_buffer->buffer.c_str());
                    continue;
            }
        }
        Statement statement;
        switch(prepare_statement(input_buffer,&statement)){
            case(PREPARE_SUCCESS):
                break;
            case (PREPARE_UNRECOGNIZED_STATEMENT):
                printf("Unrecognized keyword at start of '%s.\n",input_buffer->buffer.c_str());
                continue;
        }
        execute_statement(&statement);
        printf("Executed.\n");
            
    }
}