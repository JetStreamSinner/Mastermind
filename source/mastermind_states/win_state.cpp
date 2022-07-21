#include "win_state.h"
#include "../game_area.h"
#include "../interfaces/abstract_input_writer.h"
#include "../interfaces/abstract_input_reader.h"
#include "start_state.h"

class WinState::WinStateImpl {
public:
    bool exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader);
    std::unique_ptr<AbstractMastermindState> nextState();
};

bool WinState::WinStateImpl::exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader) {
    writer->writeMessage("You won!");
    return true;
}

std::unique_ptr<AbstractMastermindState> WinState::WinStateImpl::nextState() {
    return std::make_unique<StartState>();
}

WinState::WinState() : _impl(std::make_unique<WinState::WinStateImpl>()) {
}

bool WinState::exec(std::shared_ptr<GameArea> &area,
              const std::unique_ptr<AbstractInputWriter> &writer,
              const std::unique_ptr<AbstractInputReader> &reader) {
    return _impl->exec(area, writer, reader);
}

std::unique_ptr<AbstractMastermindState> WinState::nextState() {
    return _impl->nextState();
}

WinState::~WinState() = default;
