#pragma once

#include "../interfaces/abstract_mastermind_state.h"

class WinState : public AbstractMastermindState {
public:
    explicit WinState();
    bool exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader) final;
    std::unique_ptr<AbstractMastermindState> nextState() final;
    ~WinState() override;

private:
    class WinStateImpl;
    std::unique_ptr<WinStateImpl> _impl;
};
