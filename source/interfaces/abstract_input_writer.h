#pragma once

#include <string>

class AbstractInputWriter {
public:
    virtual void writeMessage(const std::string& message) = 0;
    virtual ~AbstractInputWriter() = default;
};