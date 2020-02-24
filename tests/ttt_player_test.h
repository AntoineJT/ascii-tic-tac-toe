it("should players be correctly named")
{
    puts("ttt_player.c"); // workaround

    check(ttt_get_player_name(PLAYER_CROSS) == "Cross");
    check(ttt_get_player_name(PLAYER_CIRCLE) == "Circle");
    check(ttt_get_player_name(PLAYER_NULL) == "ERROR");
    check(ttt_get_player_name(PLAYER_UNDEFINED) == "ERROR");
}
