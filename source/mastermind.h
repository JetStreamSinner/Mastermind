#pragma once

#include <memory>
class AbstractUserRequestAcceptor;
class AbstractMastermindState;

class Mastermind {
public:
    explicit Mastermind(std::unique_ptr<AbstractUserRequestAcceptor> &acceptor);
    void nextStep();
private:
    std::unique_ptr<AbstractMastermindState> _current_state;
    std::unique_ptr<AbstractUserRequestAcceptor> _acceptor;
};