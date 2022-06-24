#include <iostream>
#include <filesystem>
#include <string.h>

#include "cmd/cmd_proto.h"

void print_help()
{
    std::cout << "Bonjour je suis l'help" << std::endl;
    exit(1);
}

// @TODO: complete the switch statement
static void get_arg(int value, char *str)
{
    strtok_r(str, "=", &str);

    if (!str) {
        std::cerr << "Missing argument for flag: " << str << std::endl;
        exit(1);
    }
    switch (value) {
        case 's':
            std::cout << "Assigning " << str << " to -s flag" << std::endl;
            break;
        default:
            std::cerr << "Unknown flag: " << str << std::endl;
            exit(1);
    }
}

static void exec_flag(int value, char *current_str, char *arg_val)
{
    if (value == '?') {
        std::cerr << "Unknown flag: " << current_str << std::endl;
        print_help();
    }

    switch (value) {
        case 0:
            std::cout << "input file: " << current_str << std::endl;
            break;
        case 'h':
            print_help();
            break;
        case 's':
            get_arg(value, current_str);
            break;
        default:
            break;
    }
}

void cmd_parser(int ac, char **av)
{
    int ret = 0;
    size_t flag_index = 1;
    size_t counter = 1;

    while ((ret = my_getopt(ac, av, "hs")) != -1) {
        exec_flag(ret, (av[flag_index] ? av[flag_index] : NULL), (av[flag_index + 1] ? av[flag_index + 1] : NULL));
        flag_index++;
    }
}

/*
A lancer depuis le dossier Parser
    g++ .\source\cmd\core.cpp .\source\cmd\getopt.cpp -I.\include\
    .\a.exe -h -s=test testFile
*/
int main(int ac, char **av)
{
    cmd_parser(ac, av);
    return 0;
}
