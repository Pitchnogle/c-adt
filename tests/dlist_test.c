#include <criterion/criterion.h>

#include <stdlib.h> // free()

#include "../src/dlist.h"

DList list;

int *item1 = NULL;
int *item2 = NULL;
int *item3 = NULL;

void suite_setup()
{
	item1 = (int*)malloc(sizeof (int));
	item2 = (int*)malloc(sizeof (int));
	item3 = (int*)malloc(sizeof (int));

	dlist_init(&list, free);
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