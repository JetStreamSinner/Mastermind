#include "cli_user_request_acceptor.h"
#include "utils.h"
#include <iostream>

CliUserRequestAcceptor::CliUserRequestAcceptor(std::shared_ptr<std::istream> &in, std::shared_ptr<std::ostream> &out,
                                               std::shared_ptr<AbstractTargetGenerateStrategy> &target_generation_strategy) : _input_stream(in),
                                                                                                                              _output_stream(out),
                                                                                                                              _target_generation_strategy(target_generation_strategy) {
}

std::size_t CliUserRequestAcceptor::requestSuggestionsCount() const {
    std::size_t suggestions_count = 0;
    *_input_stream >> suggestions_count;
    return suggestions_count;
}

SequenceRow CliUserRequestAcceptor::requestTargetRow() const {
    if (!_target_generation_strategy) {
        throw std::runtime_error("Target request strategy is not set");
    }
    return _target_generation_strategy->getTarget();
}

SequenceRow CliUserRequestAcceptor::requestGuess() const {
    std::string raw_guess;
    std::getline(*_input_stream, raw_guess);
    return sequenceRowFromString(raw_guess);
}

void CliUserRequestAcceptor::writeMessage(const std::string &message) const {
    _output_stream->write(message.c_str(), message.size());
    _output_stream->put('\n');
}
