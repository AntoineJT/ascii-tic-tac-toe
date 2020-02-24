it("should players be correctly named")
{
    puts("ttt_player.c"); // workaround

    check(ttt_get_player_name(PLAYER_CROSS) == "Cross");
    check(ttt_get_player_name(PLAYER_CIRCLE) == "Circle");
    check(ttt_get_player_name(PLAYER_NULL) == "ERROR");
    check(ttt_get_player_name(PLAYER_UNDEFINED) == "ERROR");
}

it("should opponent be correct")
{
    check(ttt_get_opponent(PLAYER_CROSS) == PLAYER_CIRCLE);
    check(ttt_get_opponent(PLAYER_CIRCLE) == PLAYER_CROSS);
    check(ttt_get_opponent(PLAYER_UNDEFINED) == PLAYER_NULL);
    check(ttt_get_opponent(PLAYER_NULL) == PLAYER_NULL);
}
