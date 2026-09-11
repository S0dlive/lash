//
// Created by Luciani Baptiste  on 11/09/2026.
//

#include "commandmanager.h"
#include "command.h"
#include <sstream>

CommandContext commandmanager::parse(const std::string &command) {
    CommandContext ctx;
    std::istringstream ss;
    std::string token;

    if (ss >> ctx.name) {
        // ToDo Boucle
    }
}
