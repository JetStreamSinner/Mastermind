set(src main.cpp cli_user_request_acceptor.cpp game_area.cpp
        guess_checker.cpp mastermind.cpp
        mastermind_states/start_state.cpp
        mastermind_states/guess_state.cpp
        mastermind_states/win_state.cpp
        mastermind_states/lose_state.cpp
        user_input_target_generate_strategy.cpp
        utils.cpp)

add_executable(${PROJECT_NAME} ${src})