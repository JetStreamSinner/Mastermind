#include "utils.h"

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
