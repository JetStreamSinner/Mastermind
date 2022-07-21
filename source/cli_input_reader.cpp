#include "cli_input_reader.h"

#include "interfaces/abstract_target_generate_strategy.h"
#include "utils.h"
#include <istream>


class CliInputReader::CliInputReaderImpl {
public:
    explicit CliInputReaderImpl(std::shared_ptr<std::istream> in, std::shared_ptr<AbstractTargetGenerateStrategy> target_generator);
    virtual SequenceRow requestTargetRow() const;
    virtual std::size_t requestSuggestionsCount() const;
    virtual SequenceRow requestGuess() const;

private:
    std::shared_ptr<std::istream> _instr;
    std::shared_ptr<AbstractTargetGenerateStrategy> _target_generator;
};

CliInputReader::CliInputReaderImpl::CliInputReaderImpl(std::shared_ptr<std::istream> in, std::shared_ptr<AbstractTargetGenerateStrategy> target_generator)
    : _instr(std::move(in)), _target_generator(std::move(target_generator)) {
}

SequenceRow CliInputReader::CliInputReaderImpl::requestTargetRow() const {
    if (!_target_generator) {
        throw std::runtime_error("Target request strategy is not set");
    }
    return _target_generator->getTarget();
}

std::size_t CliInputReader::CliInputReaderImpl::requestSuggestionsCount() const {
    std::size_t suggestions_count = 0;
    *_instr >> suggestions_count;
    return suggestions_count;
}

SequenceRow CliInputReader::CliInputReaderImpl::requestGuess() const {
    std::string raw_guess;
    std::getline(*_instr, raw_guess);
    return sequenceRowFromString(raw_guess);
}

CliInputReader::CliInputReader(std::shared_ptr<std::istream> in, std::shared_ptr<AbstractTargetGenerateStrategy> target_generator)
    : _impl(std::make_unique<CliInputReader::CliInputReaderImpl>(in, target_generator)) {
}

SequenceRow CliInputReader::requestTargetRow() const {
    return _impl->requestTargetRow();
}

std::size_t CliInputReader::requestSuggestionsCount() const {
    return _impl->requestSuggestionsCount();
}

SequenceRow CliInputReader::requestGuess() const {
    return _impl->requestGuess();
}

CliInputReader::~CliInputReader() = default;
