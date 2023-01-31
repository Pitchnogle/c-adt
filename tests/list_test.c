#include <criterion/criterion.h>

#include <stdlib.h> // free()

#include "../src/list.h"

List list;

void suite_setup()
{
	list_init(&list, free);
}

void suite_teardown()
{
	list_destroy(&list);
}

TestSuite(list_tests, .init=suite_setup, .fini=suite_teardown);

Test(list_tests, empty)
{
	cr_expect(list_size(&list) == 0, "empty list's size should be 0");
	cr_expect(list_head(&list) == NULL, "empty list's head should be NULL");
	cr_expect(list_tail(&list) == NULL, "empty list's tail should be NULL");
}
