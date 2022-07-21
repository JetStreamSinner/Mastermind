#pragma once

#include "../interfaces/abstract_mastermind_state.h"

class LoseState : public AbstractMastermindState {
public:
    explicit LoseState();
    bool exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader) final;
    std::unique_ptr<AbstractMastermindState> nextState() final;
    ~LoseState() override;

private:
    class LoseStateImpl;
    std::unique_ptr<LoseStateImpl> _impl;
};
