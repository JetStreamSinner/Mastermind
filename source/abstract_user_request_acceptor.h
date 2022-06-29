#pragma once

#include <string>
#include "types.h"

class AbstractUserRequestAcceptor {
public:
    virtual SequenceRow requestTargetRow() const = 0;
    virtual std::size_t requestSuggestionsCount() const = 0;
    virtual SequenceRow requestGuess() const = 0;
    virtual void writeMessage(const std::string& message) const = 0;
    virtual ~AbstractUserRequestAcceptor() = default;
};