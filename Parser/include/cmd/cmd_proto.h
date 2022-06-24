/*
 * @brief custom getopt for cpp
 *
 * @param ac
 * @param av
 * @param optstring (e.g. "h:s:")
 * @return '?' if no match, 0 if it is an input file/dir, -1 when it's done, or the character of the flag
*/
int my_getopt(int ac, char *const av[], const std::string optstring);
