#pragma once

#include "types.h"

class AbstractTargetGenerateStrategy {
public:
    virtual SequenceRow getTarget() const = 0;
};