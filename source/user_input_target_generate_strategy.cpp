#include "user_input_target_generate_strategy.h"
#include "utils.h"
#include <string>
#include <iostream>

UserInputTargetGenerateStrategy::UserInputTargetGenerateStrategy(std::shared_ptr<std::istream> &input_stream) : _input_stream(input_stream) {

}

SequenceRow UserInputTargetGenerateStrategy::getTarget() const {
    _input_stream->get();
    std::string raw_guess;
    std::getline(*_input_stream, raw_guess);
    return sequenceRowFromString(raw_guess);
}