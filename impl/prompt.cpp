//
// Created by baptisteluciani on 10/09/2026.
//

#include "prompt.h"
#include <unistd.h>
#include <limits.h>
#include <cstdlib>

std::string prompt::getHost() {
    char hostname[HOST_NAME_MAX] ;
    if (gethostname(hostname, HOST_NAME_MAX) == 0) {
        return std::string(hostname);
    }
    return "localhost";
}

std::string prompt::getUser() {
    const char *user = getenv("USER");
    return user ? std::string(user) : "user";
}

std::string prompt::getPrompt() {
    return "\033[1;32m" + getUser() + "@" + getHost() + "\033[0m:"
         + "\033[1;34m" + getCwd() + "\033[0m$ ";
}
std::string prompt::getCwd() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        return std::string(cwd);
    }
    return "?";
}