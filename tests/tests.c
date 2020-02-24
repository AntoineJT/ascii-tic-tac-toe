#include "../src/vendor/bdd-for-c.h"

spec("tests")
{
    static int test_count = 0;
    static int tests_failed = 0;

    after() {
        printf("\n" "  All done!" "\n"
            "  %i tests run. %i failed." "\n", test_count, tests_failed);
    }

    before() {
        puts("  Starting the tests...\n");
    }

    before_each() {
        ++test_count;
        ++tests_failed;
    }

    after_each() {
        --tests_failed;
    }

    #include "../src/equals.h"
    #include "equals_test.h"

    #include "../src/game/ttt_player.h"
    #include "ttt_player_test.h"
}
