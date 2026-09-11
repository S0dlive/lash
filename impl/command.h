//
// Created by Luciani Baptiste  on 11/09/2026.
//

#ifndef LASH_COMMAND_H
#define LASH_COMMAND_H
#include <vector>
#include <string>
#include <unordered_map>

struct CommandContext {
    std::string name;
    std::vector<std::string> args;
    std::unordered_map<std::string, std::string> flags;
};

class command {
public:
    virtual ~command() = default;
    virtual std::string getcmdname() = 0;
    virtual std::vector<std::string> getdescription() = 0;
    virtual void execute(const CommandContext& ctx) = 0;
};


#endif //LASH_COMMAND_H
