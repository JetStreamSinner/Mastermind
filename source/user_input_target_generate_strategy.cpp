#include "user_input_target_generate_strategy.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <utility>

class UserInputTargetGenerateStrategy::UserInputTargetGenerateStrategyImpl {
public:
    explicit UserInputTargetGenerateStrategyImpl(std::shared_ptr<std::istream> input_stream);
    SequenceRow getTargetRow() const;

private:
    std::shared_ptr<std::istream> _input_stream;
};

UserInputTargetGenerateStrategy::UserInputTargetGenerateStrategyImpl::UserInputTargetGenerateStrategyImpl(std::shared_ptr<std::istream> input_stream) : _input_stream(std::move(input_stream)) {
}

SequenceRow UserInputTargetGenerateStrategy::UserInputTargetGenerateStrategyImpl::getTargetRow() const {
    _input_stream->get();
    std::string raw_guess;
    std::getline(*_input_stream, raw_guess);
    return sequenceRowFromString(raw_guess);
}

UserInputTargetGenerateStrategy::UserInputTargetGenerateStrategy(std::shared_ptr<std::istream> input_stream)
    : _impl(std::make_unique<UserInputTargetGenerateStrategy::UserInputTargetGenerateStrategyImpl>(std::move(input_stream))) {
}

SequenceRow UserInputTargetGenerateStrategy::getTarget() const {
    return _impl->getTargetRow();
}

UserInputTargetGenerateStrategy::~UserInputTargetGenerateStrategy() = default;
