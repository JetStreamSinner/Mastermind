#include "cli_user_request_acceptor.h"
#include <iostream>
#include "utils.h"

CliUserRequestAcceptor::CliUserRequestAcceptor(std::shared_ptr<std::istream> &in, std::shared_ptr<std::ostream> &out) : _input_stream(in),
                                                                                                                        _output_stream(out) {
}

std::size_t CliUserRequestAcceptor::requestSuggestionsCount() const {
    std::size_t suggestions_count = 0;
    *_input_stream >> suggestions_count;
    return suggestions_count;
}

SequenceRow CliUserRequestAcceptor::requestTargetRow() const {
    _input_stream->get();
    std::string raw_guess;
    std::getline(*_input_stream, raw_guess);
    return sequenceRowFromString(raw_guess);
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
