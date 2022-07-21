#pragma once

#include <memory>
class AbstractUserRequestAcceptor;
class AbstractInputWriter;
class AbstractInputReader;

class Mastermind {
public:
    explicit Mastermind(std::unique_ptr<AbstractInputWriter> writer, std::unique_ptr<AbstractInputReader> reader);
    void nextStep();
    ~Mastermind();

private:
    class MastermindImpl;
    std::unique_ptr<MastermindImpl> _impl;
};