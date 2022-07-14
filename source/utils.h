#pragma once

#include "types.h"
#include <string>

SequenceRow sequenceRowFromString(const std::string &str);
std::string stringFromSequenceRow(const SequenceRow &sequence);