#pragma once

#include "../interfaces/abstract_mastermind_state.h"

class GuessState : public AbstractMastermindState {
public:
    explicit GuessState();
    bool exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader) final;
    std::unique_ptr<AbstractMastermindState> nextState() final;
    ~GuessState() override;

private:
    class GuessStateImpl;
    std::unique_ptr<GuessStateImpl> _impl;
};
