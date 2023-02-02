/*
This is clone of `dlist_test` but uses a simple data type
*/
#include <criterion/criterion.h>

#include "../src/dlist.h"

DList list;

void suite_setup()
{
	dlist_init(&list, NULL);
}

void suite_teardown()
{
	dlist_destroy(&list);
}

TestSuite(list_tests, .init=suite_setup, .fini=suite_teardown);

Test(list_tests, empty)
{
	cr_expect(dlist_size(&list) == 0, "empty dlist's size should be 0");
	cr_expect(dlist_head(&list) == NULL, "empty dlist's head should be NULL");
	cr_expect(dlist_tail(&list) == NULL, "empty dlist's tail should be NULL");
}

// TODO -- add more comprehensive tests