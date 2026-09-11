//
// Created by Luciani Baptiste  on 11/09/2026.
//

#ifndef LASH_COMMANDMANAGER_H
#define LASH_COMMANDMANAGER_H
#include <string>
#include <memory>

#include "command.h"


class commandmanager {
private:
    CommandContext parse(const std::string &command);
    std::unordered_map<std::string, std::unique_ptr<command>> commands;
    int execute_system_command(const CommandContext &ctx);
public:
    commandmanager() = default;

    // Enregistrement de commandes internes (Built-ins)
    void register_command(std::unique_ptr<command> cmd);
    void unregister_command(const std::string &name);

    // Exécution globale (built-in ou système)
    int run_command(const std::string &input_line);

};




#endif //LASH_COMMANDMANAGER_H
