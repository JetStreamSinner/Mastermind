#pragma once

#include "types.h"
#include <memory>

class GuessChecker {
public:
    explicit GuessChecker(const SequenceRow &target_row);
    SequenceRow makeHintRow(const SequenceRow &guess_row) const;
    bool guessValid(const SequenceRow &guess_row) const;
    ~GuessChecker();

private:
    class GuessCheckerImpl;
    std::unique_ptr<GuessCheckerImpl> _impl;
};