//
// Created by baptisteluciani on 10/09/2026.
//

#ifndef LASH_PROMPT_H
#define LASH_PROMPT_H
#include <string>


class prompt {
public:
    static std::string getUser();
    static std::string getHost();
    static std::string getCwd();
    static std::string getPrompt();
};


#endif //LASH_PROMPT_H
