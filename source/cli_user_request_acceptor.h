#pragma once

#include <memory>
#include "abstract_user_request_acceptor.h"

class CliUserRequestAcceptor : public AbstractUserRequestAcceptor {
public:
    CliUserRequestAcceptor(std::shared_ptr<std::istream> &in, std::shared_ptr<std::ostream> &out);
    SequenceRow requestTargetRow() const final;
    std::size_t requestSuggestionsCount() const final;
    SequenceRow requestGuess() const final;
    void writeMessage(const std::string& message) const final;
private:
    std::shared_ptr<std::istream> _input_stream;
    std::shared_ptr<std::ostream> _output_stream;
};