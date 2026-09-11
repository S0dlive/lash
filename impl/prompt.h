//
// Created by baptisteluciani on 10/09/2026.
//

#ifndef LASH_PROMPT_H
#define LASH_PROMPT_H
#include <filesystem>
#include <string>


class prompt {
private:
    static std::filesystem::path actualCwd;
public:
    static std::string getUser();
    static std::string getHost();
    static std::string getCwd();
    static std::string getPrompt();
};


#endif //LASH_PROMPT_H
