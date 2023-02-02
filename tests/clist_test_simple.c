/*
This is clone of `clist_test` but uses a simple data type
*/
#include <criterion/criterion.h>

#include "../src/clist.h"

CList list;

void suite_setup()
{
	clist_init(&list, NULL);
}

void suite_teardown()
{
	clist_destroy(&list);
}

TestSuite(list_tests, .init=suite_setup, .fini=suite_teardown);

Test(list_tests, empty)
{
	cr_expect(clist_size(&list) == 0, "empty dlist's size should be 0");
	cr_expect(clist_head(&list) == NULL, "empty dlist's head should be NULL");
}

// TODO -- add more comprehensive tests