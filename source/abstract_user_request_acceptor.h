#pragma once

#include <string>
#include "types.h"

class AbstractUserRequestAcceptor {
public:
    virtual SequenceRow requestTargetRow() const = 0;
    virtual int requestSuggestionsCount() const = 0;
    virtual SequenceRow requestGuess() const = 0;
    virtual std::string lastDescriptionResponse() const = 0;
    virtual ~AbstractUserRequestAcceptor() = default;
};