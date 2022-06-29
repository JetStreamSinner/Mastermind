#pragma once

#include <memory>
#include "abstract_user_request_acceptor.h"

class CliUserRequestAcceptor : public AbstractUserRequestAcceptor {
public:
    SequenceRow requestTargetRow() const final;
    int requestSuggestionsCount() const final;
    SequenceRow requestGuess() const final;
    void writeMessage(const std::string& message) const final;
};