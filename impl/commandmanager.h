//
// Created by Luciani Baptiste  on 11/09/2026.
//

#ifndef LASH_COMMANDMANAGER_H
#define LASH_COMMANDMANAGER_H
#include <string>

#include "command.h"


class commandmanager {
private:
    CommandContext parse(const std::string &command);
    std::unordered_map<std::string, std::unique_ptr<command>> commands;
public:
    void register_command(Command *command);
    void unregister_command(Command *command);
    int run_command(Command *command);

};




#endif //LASH_COMMANDMANAGER_H
