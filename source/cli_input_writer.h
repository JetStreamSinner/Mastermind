#pragma once

#include "interfaces/abstract_input_writer.h"
#include <memory>

class CliInputWriter : public AbstractInputWriter {
public:
    explicit CliInputWriter(std::shared_ptr<std::ostream> in);
    void writeMessage(const std::string &message) override;
    ~CliInputWriter() override;

private:
    class CliInputWriterImpl;
    std::unique_ptr<CliInputWriterImpl> _impl;
};