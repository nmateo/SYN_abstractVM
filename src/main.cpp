#include "../include/definition.hpp"
#include "../include/core.hpp"
#include "../include/Error.hpp"
#include "../include/parser.hpp"
#include <memory>
#include <vector>
#include <regex>

int main(int ac, char **av)
{
    std::unique_ptr<Core> core = std::make_unique<Core>();
    std::vector<std::string> lines;
    std::unique_ptr<Parser> parser = std::make_unique<Parser>();

    try
    {
        if (ac == 1)
        {
            core->setMode(1);
            lines = parser->readPrompt();
        } else if (ac == 2)
        {
            core->setMode(2);
            lines = parser->readFile(av[1]);
        } else
        {
            std::cout << "USAGE:\n\tprompt mode:\t./abstractVM\n\tfile mode:\t./abstractVM [path]" << std::endl;
            return (0);
        }
        for (size_t i = 0; i != lines.size(); i++)
        {
            core->execInstructions(lines[i]);
            if (core->isExited() == true)
                break;
        }
        if (core->isExited() == false)
            throw Error("Exit instruction missing");
    } catch (Error const &e)
    {
        std::cerr << "An exception happened: " << e.what() << std::endl;
        return (84);
    }
    return (0);
}
