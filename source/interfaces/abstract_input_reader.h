#pragma once

#include "../types.h"

class AbstractInputReader {
public:
    virtual SequenceRow requestTargetRow() const = 0;
    virtual std::size_t requestSuggestionsCount() const = 0;
    virtual SequenceRow requestGuess() const = 0;
    virtual ~AbstractInputReader() = default;
};