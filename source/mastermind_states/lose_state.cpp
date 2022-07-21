#include "lose_state.h"
#include "../game_area.h"
#include "../interfaces/abstract_input_writer.h"
#include "../interfaces/abstract_input_reader.h"
#include "start_state.h"

class LoseState::LoseStateImpl {
public:
    bool exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader);
    std::unique_ptr<AbstractMastermindState> nextState();
};

bool LoseState::LoseStateImpl::exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader) {
    writer->writeMessage("You lose!");
    return true;
}

std::unique_ptr<AbstractMastermindState> LoseState::LoseStateImpl::nextState() {
    return std::make_unique<StartState>();
}

LoseState::LoseState() : _impl(std::make_unique<LoseState::LoseStateImpl>()) {
}

bool LoseState::exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader) {
    return _impl->exec(area, writer, reader);
}

std::unique_ptr<AbstractMastermindState> LoseState::nextState() {
    return _impl->nextState();
}

LoseState::~LoseState() = default;
