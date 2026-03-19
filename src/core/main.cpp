#include <iostream>
#include <string>
#include <cstring>

typedef struct {
    std::string buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

void print_prompt() { printf("db > "); }

InputBuffer* new_input_buffer() {
    InputBuffer* input_buffer = new InputBuffer;
    input_buffer->buffer = "";
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;
    return input_buffer;
}

void read_input(InputBuffer* input_buffer) {
    std::getline(std::cin, input_buffer->buffer);
    input_buffer->input_length = input_buffer->buffer.size();
    input_buffer->buffer_length = input_buffer->buffer.capacity();
}

void close_input_buffer(InputBuffer* input_buffer) {
    free(input_buffer);
}

int main(int argc , char* argv[]){
    InputBuffer* input_buffer = new_input_buffer();
    
    while(true){
        print_prompt();
        read_input(input_buffer);
        if(input_buffer->buffer == ".exit"){
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        }else{
            printf("Unrecognized command '%s'. \n",input_buffer->buffer.c_str());
        }
    }
}