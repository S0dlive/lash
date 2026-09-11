//
// Created by baptisteluciani on 11/09/2026.
//

#ifndef LASH_CD_COMMAND_H
#define LASH_CD_COMMAND_H

#include "command.h"
#include <unistd.h>

class cd_command : public command {
public:
    std::string getcmdname() override { return "cd"; }
    std::vector<std::string> getdescription() override { return {"cd <dir>", "Change current directory"}; }
    void execute(const CommandContext &ctx) override {
        std::string target = ctx.args.empty() ? getenv("HOME") : ctx.args[0];
        if (chdir(target.c_str()) != 0) {
            std::perror("lash: cd");
        }
    }
};


#endif //LASH_CD_COMMAND_H
