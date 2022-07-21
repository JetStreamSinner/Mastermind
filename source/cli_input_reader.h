#pragma once

#include "interfaces/abstract_input_reader.h"
#include <memory>

class AbstractTargetGenerateStrategy;

class CliInputReader : public AbstractInputReader {
public:
    explicit CliInputReader(std::shared_ptr<std::istream> in, std::shared_ptr<AbstractTargetGenerateStrategy> target_generator);
    SequenceRow requestTargetRow() const override;
    std::size_t requestSuggestionsCount() const override;
    SequenceRow requestGuess() const override;
    ~CliInputReader() override;
private:
    class CliInputReaderImpl;
    std::unique_ptr<CliInputReaderImpl> _impl;
};