#include "utils.h"
#include <iostream>

#include <algorithm>
#include <iterator>
#include <sstream>

SequenceRow sequenceRowFromString(const std::string &str) {
    std::stringstream ss(str);
    SequenceRow out;
    std::transform(std::istream_iterator<int>(ss), std::istream_iterator<int>(), std::back_inserter(out), [](int val) {
        return static_cast<Color>(val);
    });
    return std::move(out);
}

std::string stringFromSequenceRow(const SequenceRow &sequence) {
    std::stringstream ss;
    std::for_each(sequence.begin(), sequence.end(), [&ss](auto sequence_item) {
        ss << static_cast<int>(sequence_item) << " ";
    });
    return std::move(ss.str());
}