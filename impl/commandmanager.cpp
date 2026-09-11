//
// Created by Luciani Baptiste  on 11/09/2026.
//

#include "commandmanager.h"

#include <iostream>
#include <memory>

#include "command.h"
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>

CommandContext commandmanager::parse(const std::string &command) {
    CommandContext ctx;
    std::istringstream ss(command);
    std::string token;

    if (!(ss >> ctx.name)) {
        return ctx;
    }

    while (ss >> token) {
        if (token.rfind("--",0) == 0) {
            auto pos = token.rfind("=");
            if (pos != std::string::npos) {
                ctx.flags[token.substr(2,pos - 2)] = token.substr(pos + 1);
            }
            else {
                ctx.flags[token.substr(2)] = "true";
            }
        }
        else if (token.rfind("-",0) == 0 && token.size() > 1) {
            ctx.flags[token.substr(1)] = "true";
        }
        else {
            ctx.args.push_back(token);
        }
    }
    return ctx;
}

void commandmanager::register_command(std::unique_ptr<command> cmd) {
    if (cmd) {
        std::string name = cmd->getcmdname();
        commands[name] = std::move(cmd);
    }
}

void commandmanager::unregister_command(const std::string &name) {
    commands.erase(name);
}


int commandmanager::execute_system_command(const CommandContext &ctx) {
    std::vector<char*> args;
    args.push_back(const_cast<char*>(ctx.name.c_str()));

    for (const auto &arg : ctx.args) {
        args.push_back(const_cast<char*>(arg.c_str()));
    }
    args.push_back(nullptr);

    pid_t pid = fork();

    if (pid == 0) {
        execvp(args[0], args.data());

        std::cerr << "lash: command not found: " << ctx.name << std::endl;
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
        return -1;
    } else {
        std::perror("lash: fork failed");
        return -1;
    }
}

int commandmanager::run_command(const std::string &input_line) {
    CommandContext ctx = parse(input_line);

    if (ctx.name.empty()) {
        return 0;
    }

    auto it = commands.find(ctx.name);
    if (it != commands.end()) {
        it->second->execute(ctx);
        return 0;
    }

    return execute_system_command(ctx);
}