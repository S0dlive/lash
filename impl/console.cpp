//
// Created by baptisteluciani on 10/09/2026.
//

#include "console.h"
#include "prompt.h"
#include "cd_command.h"
#include <iostream>
#include <ostream>

void console::run() {
    std::string line;
    m_commandManager.register_command(std::make_unique<cd_command>());
    while (m_running) {
        std::cout << prompt::getPrompt() << std::flush;
        if (!std::getline(std::cin, line)) {
            break;
        }
        if (line.empty()) {
            continue;
        }
        processInput(line);
    }
}

void console::processInput(const std::string& line) {
    if (line == "exit") {
        m_running = false;
        return;
    }

    m_commandManager.run_command(line);
}