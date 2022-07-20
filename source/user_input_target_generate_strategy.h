#pragma once

#include "interfaces/abstract_target_generate_strategy.h"
#include <memory>


class UserInputTargetGenerateStrategy : public AbstractTargetGenerateStrategy {
public:
    explicit UserInputTargetGenerateStrategy(std::shared_ptr<std::istream> input_stream);
    SequenceRow getTarget() const override;
    ~UserInputTargetGenerateStrategy();

private:
    class UserInputTargetGenerateStrategyImpl;
    std::unique_ptr<UserInputTargetGenerateStrategyImpl> _impl;
};