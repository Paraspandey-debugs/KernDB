#include "input_buffer.h"
#include <iostream>
#include <cstdio>

InputBuffer::InputBuffer() : buffer_() {}

void InputBuffer::read_input() {
    if (!std::getline(std::cin, buffer_)) {
        std::printf("Error reading input\n");
        std::exit(EXIT_FAILURE);
    }
}

void InputBuffer::print_prompt() const {
    std::printf("db > ");
}