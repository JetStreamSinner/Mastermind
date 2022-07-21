#include "start_state.h"
#include "../game_area.h"
#include "../guess_checker.h"
#include "../interfaces/abstract_input_writer.h"
#include "../interfaces/abstract_input_reader.h"
#include "guess_state.h"

class StartState::StartStateImpl {
public:
    bool exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader);
    std::unique_ptr<AbstractMastermindState> nextState();
};

bool StartState::StartStateImpl::exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader) {
    writer->writeMessage("Welcome to the game");
    writer->writeMessage("Write suggestions count");
    const std::size_t suggestions_count = reader->requestSuggestionsCount();
    writer->writeMessage("Write target sequence");
    const SequenceRow target_row = reader->requestTargetRow();

    auto guess_checker = std::make_unique<GuessChecker>(target_row);
    area = std::make_shared<GameArea>(suggestions_count, std::move(guess_checker));
    return true;
}

std::unique_ptr<AbstractMastermindState> StartState::StartStateImpl::nextState() {
    return std::make_unique<GuessState>();
}

StartState::StartState() : _impl(std::make_unique<StartState::StartStateImpl>()) {
}

bool StartState::exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader) {
    return _impl->exec(area, writer, reader);
}

std::unique_ptr<AbstractMastermindState> StartState::nextState() {
    return _impl->nextState();
}

StartState::~StartState() = default;
