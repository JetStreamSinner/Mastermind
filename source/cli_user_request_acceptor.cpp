#include "cli_user_request_acceptor.h"
#include <iostream>

CliUserRequestAcceptor::CliUserRequestAcceptor(std::shared_ptr<std::istream> &in, std::shared_ptr<std::ostream> &out) : _input_stream(in),
                                                                                                                        _output_stream(out) {
}

int CliUserRequestAcceptor::requestSuggestionsCount() const {
    std::size_t suggestions_count = 0;
    *_input_stream >> suggestions_count;
    return suggestions_count;
}

SequenceRow CliUserRequestAcceptor::requestTargetRow() const {
    std::string row;
    *_input_stream >> row;
    return SequenceRow{1, 2, 3};
}

SequenceRow CliUserRequestAcceptor::requestGuess() const {
    return SequenceRow {1, 2, 3};
}

void CliUserRequestAcceptor::writeMessage(const std::string &message) const {
    _output_stream->write(message.c_str(), message.size());
    _output_stream->put('\n');
}
