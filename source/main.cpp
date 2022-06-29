#include "mastermind.h"
#include "abstract_mastermind_state.h"
#include "cli_user_request_acceptor.h"

int main(int argc, char * argv[])
{
    std::unique_ptr<AbstractUserRequestAcceptor> acceptor = std::make_unique<CliUserRequestAcceptor>();
    Mastermind mastermind(acceptor);
    mastermind.nextStep();
    return 0;
}