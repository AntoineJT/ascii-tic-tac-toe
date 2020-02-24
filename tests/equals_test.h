it("should work for similar numbers")
{
    puts("equals.c"); // workaround
    check(int_3_equals(3, 3, 3));
}

it("should not work for 2 differents numbers")
{
    check(!int_3_equals(3, 2, 2));
}

it("should not work for 3 different numbers")
{
    check(!int_3_equals(3, 2, 1));
}
