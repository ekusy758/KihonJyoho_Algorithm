#include <stdio.h>
#include <stdlib.h>

int fee(int age) {
    if (age < 0) return -1;

    if (age <= 3) {
        return 100;
    } else if (age <= 9) {
        return 300;
    } else {
        return 500;
    }
}

int main(int argc, char **argv) {
    if (argc == 2) {
        printf("%sÎ‚Ì“üê—¿‚Í %d‰~‚Å‚·.\n", argv[1], fee(atoi(argv[1])));
    }
    return 0;
}