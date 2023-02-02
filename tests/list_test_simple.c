/*
This is clone of `list_test` but uses a simple data type
*/
#include <criterion/criterion.h>

#include "../src/list.h"

List list;

void suite_setup()
{
	list_init(&list, NULL);
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

Test(list_tests, insert_into_empty)
{
	// Give our item a value
	int item1 = 1;

	cr_expect(list_insert_next(&list, NULL, &item1) == 0, "insert into empty list should return 0");
	cr_expect(list_size(&list) == 1, "list's size should be 1");
	cr_expect(list_head(&list) != NULL, "list's head should be not NULL");
	cr_expect(list_tail(&list) != NULL, "list's tail should be not NULL");
	cr_expect(list_is_head(&list, list_head(&list)) == 1, "head should be at the head of the list");
	cr_expect(list_is_tail(list_tail(&list)) == 1, "tail should be at the tail of the list");
	cr_expect(list_next(list_head(&list)) == NULL, "next should be NULL for head of one element list");
	cr_expect(list_next(list_tail(&list)) == NULL, "next should be NULL for tail of one element list");
	cr_expect(list_data(list_head(&list)) == &item1, "head should be the item inserted");
	cr_expect(list_data(list_tail(&list)) == &item1, "tail should be the item inserted");
}

Test(list_tests, insert_after_head)
{
	// Give out items some values
	int item1 = 1;
	int item2 = 2;

	cr_expect(list_insert_next(&list, NULL, &item1) == 0, "insert into empty list should return 0");
	cr_expect(list_size(&list) == 1, "list's size should be 1");
	cr_expect(list_insert_next(&list, list_head(&list), &item2) == 0, "insert after head should return 0");
	cr_expect(list_size(&list) == 2, "list's size should be 2");
	cr_expect(list_head(&list) != NULL, "list's head should be not NULL");
	cr_expect(list_tail(&list) != NULL, "list's tail should be not NULL");
	cr_expect(list_next(list_head(&list)) != NULL, "next should be not NULL for head of two element list");
	cr_expect(list_next(list_tail(&list)) == NULL, "next should be NULL for tail of two element list");
	cr_expect(list_data(list_head(&list)) == &item1, "head should be the first item inserted");
	cr_expect(list_data(list_tail(&list)) == &item2, "tail should be the second item inserted");
}

Test(list_tests, insert_twice_at_head)
{
	// Give out items some values
	int item1 = 1;
	int item2 = 2;
	int item3 = 3;

	cr_expect(list_insert_next(&list, NULL, &item1) == 0, "insert into empty list should return 0");
	cr_expect(list_size(&list) == 1, "list's size should be 1");
	cr_expect(list_insert_next(&list, NULL, &item2) == 0, "insert after head should return 0");
	cr_expect(list_size(&list) == 2, "list's size should be 2");
	cr_expect(list_insert_next(&list, NULL, &item3) == 0, "insert after head should return 0");
	cr_expect(list_size(&list) == 3, "list's size should be 3");
	cr_expect(list_head(&list) != NULL, "list's head should be not NULL");
	cr_expect(list_tail(&list) != NULL, "list's tail should be not NULL");
	cr_expect(list_next(list_head(&list)) != NULL, "next should be not NULL for head of two element list");
	cr_expect(list_next(list_tail(&list)) == NULL, "next should be NULL for tail of two element list");
	cr_expect(list_data(list_head(&list)) == &item3, "head should be the third item inserted");
	cr_expect(list_data(list_tail(&list)) == &item1, "tail should be the first item inserted");
}

Test(list_tests, insert_twice_at_tail)
{
	// Give out items some values
	int item1 = 1;
	int item2 = 2;
	int item3 = 3;

	cr_expect(list_insert_next(&list, NULL, &item1) == 0, "insert into empty list should return 0");
	cr_expect(list_size(&list) == 1, "list's size should be 1");
	cr_expect(list_insert_next(&list, list_tail(&list), &item2) == 0, "insert after tail should return 0");
	cr_expect(list_size(&list) == 2, "list's size should be 2");
	cr_expect(list_insert_next(&list, list_tail(&list), &item3) == 0, "insert after tail should return 0");
	cr_expect(list_size(&list) == 3, "list's size should be 3");
	cr_expect(list_head(&list) != NULL, "list's head should be not NULL");
	cr_expect(list_tail(&list) != NULL, "list's tail should be not NULL");
	cr_expect(list_next(list_head(&list)) != NULL, "next should be not NULL for head of three element list");
	cr_expect(list_next(list_tail(&list)) == NULL, "next should be NULL for tail of three element list");
	cr_expect(list_data(list_head(&list)) == &item1, "head should be the first item inserted");
	cr_expect(list_data(list_tail(&list)) == &item3, "tail should be the third item inserted");
}

// TODO -- remove at head
// TODO -- remove after head
