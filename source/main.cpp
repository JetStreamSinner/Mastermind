#include "cli_input_reader.h"
#include "cli_input_writer.h"
#include "interfaces/abstract_mastermind_state.h"
#include "mastermind.h"
#include "user_input_target_generate_strategy.h"
#include <iostream>

int main(int argc, char *argv[]) {
    std::shared_ptr<std::istream> in = std::shared_ptr<std::istream>(&std::cin, [](std::istream *is) {

    });
    std::shared_ptr<std::ostream> out = std::shared_ptr<std::ostream>(&std::cout, [](std::ostream *os) {

    });

    std::shared_ptr<AbstractTargetGenerateStrategy> generation_strategy = std::make_shared<UserInputTargetGenerateStrategy>(in);

    std::unique_ptr<AbstractInputWriter> writer = std::make_unique<CliInputWriter>(out);
    std::unique_ptr<AbstractInputReader> reader = std::make_unique<CliInputReader>(in, generation_strategy);

    Mastermind mastermind(std::move(writer), std::move(reader));
    while (true) {
        mastermind.nextStep();
    }
    return 0;
}