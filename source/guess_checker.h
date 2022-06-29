#pragma once

#include "types.h"

class GuessChecker {
public:
    explicit GuessChecker(const SequenceRow &target_row);
    SequenceRow makeHintRow(const SequenceRow &guess_row) const;
};