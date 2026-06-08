#if defined(_DEBUG) && defined(ENABLE_CRTDBG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int main(int argc, char** argv) {

#if defined(_DEBUG) && defined(ENABLE_CRTDBG)
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    (void) argc;
    (void) argv;

    printf("Hello\n");

    return 0;
}
