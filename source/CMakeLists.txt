set(src main.cpp game_area.cpp
        guess_checker.cpp mastermind.cpp
        mastermind_states/start_state.cpp
        mastermind_states/guess_state.cpp
        mastermind_states/win_state.cpp
        mastermind_states/lose_state.cpp
        user_input_target_generate_strategy.cpp
        cli_input_reader.cpp
        cli_input_writer.cpp
        utils.cpp)

add_executable(${PROJECT_NAME} ${src})