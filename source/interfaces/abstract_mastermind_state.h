#pragma once

#include <memory>
class AbstractUserRequestAcceptor;
class AbstractInputReader;
class AbstractInputWriter;
class GameArea;

class AbstractMastermindState {
public:
    virtual bool exec(std::shared_ptr<GameArea> &area,
                      const std::unique_ptr<AbstractInputWriter> &writer,
                      const std::unique_ptr<AbstractInputReader> &reader) = 0;
    virtual std::unique_ptr<AbstractMastermindState> nextState() = 0;
    virtual ~AbstractMastermindState() = default;
};
