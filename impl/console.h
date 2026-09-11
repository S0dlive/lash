//
// Created by baptisteluciani on 10/09/2026.
//

#ifndef LASH_CONSOLE_H
#define LASH_CONSOLE_H
#include <string>
#include "commandmanager.h"


class console {
private:
    bool m_running{true};
    commandmanager m_commandManager;

    void processInput(const std::string& line);

public:
    console() = default;
    void run();
};

#endif //LASH_CONSOLE_H
