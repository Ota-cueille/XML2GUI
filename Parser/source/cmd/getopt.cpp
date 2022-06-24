#include <iostream>

int optind = 1;

int my_getopt(int ac, char *const av[], const std::string optstring)
{
    if (optind >= ac)
        return -1;
    if (av[optind][0] != '-')
        return 0;

    int c = av[optind][1];
    for (int i : optstring) {
        if (c == i && i != ':') {
            optind++;
            return c;
        }
    }
    optind++;
    return '?';    
}
