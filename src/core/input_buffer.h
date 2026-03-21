#ifndef INPUT_BUFFER_H
#define INPUT_BUFFER_H

#include <string>

class InputBuffer {
public:
    InputBuffer();
    void read_input();        // reads a line from stdin
    void print_prompt() const;
    const std::string& get_buffer() const { return buffer_; }

private:
    std::string buffer_;
};

#endif // INPUT_BUFFER_H