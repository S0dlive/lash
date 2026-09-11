//
// Created by baptisteluciani on 10/09/2026.
//

#include "console.h"
#include "prompt.h"

#include <iostream>
#include <ostream>

void console::run() {
    std::string line;

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
        std::filesystem::current_path().clear();
        std::filesystem::current_path("/tmp");
        return;
    }
    std::cout << "[Reçu] " << line << "\n";
}