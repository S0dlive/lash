//
// Created by baptisteluciani on 10/09/2026.
//

#ifndef LASH_CONSOLE_H
#define LASH_CONSOLE_H
#include <string>


    class console {
    private:
        bool m_running{true};
        void processInput(const std::string& input);

    public:
        console() = default;
        void run();
    };

#endif //LASH_CONSOLE_H
