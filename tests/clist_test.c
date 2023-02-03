#include <criterion/criterion.h>

#include <stdlib.h> // free()

#include "../src/clist.h"

CList list;

int *item1 = NULL;
int *item2 = NULL;
int *item3 = NULL;

void suite_setup()
{
	item1 = (int*)malloc(sizeof (int));
	item2 = (int*)malloc(sizeof (int));
	item3 = (int*)malloc(sizeof (int));

	clist_init(&list, free);
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

Test(list_tests, insert_into_empty)
{
	// Give our item a value
	*item1 = 1;

	CList_Element* element = clist_head(&list);
	cr_expect(clist_head(&list) == NULL, "empty list's head should be NULL");
	cr_expect(element == NULL, "empty list's head should be NULL");

	cr_expect(clist_insert_next(&list, element, item1) == 0, "insert into empty list should return 0");
	cr_expect(clist_size(&list) == 1, "list's size should be 1");
	cr_expect(clist_head(&list) != NULL, "list's head should be not NULL");
	
	element = clist_head(&list);
	cr_expect(clist_next(element) == element, "next should be self referential for one element list");
	cr_expect(clist_data(element) == item1, "head should be the item inserted");
	cr_expect(clist_data(clist_head(&list)) == item1, "head should be the item inserted");
}

Test(list_tests, insert_twice_at_head)
{
	// Give out items some values
	*item1 = 1;
	*item2 = 2;

	CList_Element* element = clist_head(&list);
	cr_expect(clist_head(&list) == NULL, "empty list's head should be NULL");
	cr_expect(element == NULL, "empty list's head should be NULL");

	cr_expect(clist_insert_next(&list, element, item1) == 0, "insert into empty list should return 0");
	cr_expect(clist_size(&list) == 1, "list's size should be 1");
	cr_expect(clist_head(&list) != NULL, "list's head should be not NULL");

	element = clist_head(&list);
	cr_expect(clist_insert_next(&list, element, item2) == 0, "insert after head should return 0");
	cr_expect(clist_size(&list) == 2, "list's size should be 2");

	element = clist_head(&list);
	cr_expect(clist_next(element) != NULL, "next should be not NULL for circular list");
	cr_expect(clist_data(element) == item1, "element should be the first item inserted");

	element = clist_next(element);
	cr_expect(clist_next(element) != NULL, "next should be not NULL for circular list");
	cr_expect(clist_data(element) == item2, "element should be the second item inserted");

	element = clist_next(element);
	cr_expect(clist_data(element) == item1, "element should be the first item inserted");
}
