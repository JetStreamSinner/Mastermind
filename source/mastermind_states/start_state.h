#pragma once

#include "../interfaces/abstract_mastermind_state.h"

class StartState : public AbstractMastermindState {
public:
    explicit StartState();
    bool exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader) final;
    std::unique_ptr<AbstractMastermindState> nextState() final;
    ~StartState() override;

private:
    class StartStateImpl;
    std::unique_ptr<StartStateImpl> _impl;
};
