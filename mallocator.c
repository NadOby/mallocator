#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "cmdline.h"

/*
 * TODO use systen dependant checks http://nadeausoftware.com/articles/2012/09/c_c_tip_how_get_physical_memory_size_system
 * TODO check swap, used memory
 */
unsigned long getTotalSystemMemory()
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages * page_size;
}

int main(int argc, char ** argv) {
    int MULTIPLICATOR;
    char UNITS[16];
    unsigned long ALLMEM;

    struct gengetopt_args_info ai;
    if (cmdline_parser(argc, argv, &ai) != 0) {
        exit(1);
    }
    /*
    printf("ai.units_arg: %s\n", ai.units_arg);
    printf("ai.mem_arg: %d\n", ai.mem_arg);
    printf("ai.percentage_arg: %d\n", ai.percentage_arg);
    */
    switch(*ai.units_arg){
        case 'K':
            MULTIPLICATOR = 1024;
            strcpy(UNITS ,"Kilobytes");
            break;
        case 'M':
            MULTIPLICATOR = 1024*1024;
            strcpy(UNITS ,"Megabytes");
            break;
        case 'G':
            MULTIPLICATOR = 1024*1024*1024;
            strcpy(UNITS ,"Gigabytes");
            break;
    }
    if (ai.mem_arg != 0) {
    }
    ALLMEM = getTotalSystemMemory()/MULTIPLICATOR;
    printf("System memory usage is : %zu %s\n", ALLMEM, UNITS);
    exit(0);
}
