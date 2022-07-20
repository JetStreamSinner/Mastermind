#pragma once

#include <memory>
class AbstractUserRequestAcceptor;

class Mastermind {
public:
    explicit Mastermind(std::unique_ptr<AbstractUserRequestAcceptor> acceptor);
    void nextStep();
    ~Mastermind();

private:
    class MastermindImpl;
    std::unique_ptr<MastermindImpl> _impl;
};