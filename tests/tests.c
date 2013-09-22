#include <check.h>
#include <stdint.h>
#include "emlist.h"
#include <stdio.h>
#include <stdlib.h>

START_TEST (test_init)
{
    LinkedList list;
    emlist_initialize(&list);
    ck_assert(list.head == NULL);
}
END_TEST

START_TEST (test_insert)
{
    LinkedList list;
    emlist_initialize(&list);
    void* value = (void*)1;
    ck_assert(emlist_insert(&list, value));
    ck_assert(emlist_contains(&list, value));
}
END_TEST

START_TEST (test_contains)
{
    LinkedList list;
    emlist_initialize(&list);
    void* value = (void*)1;
    emlist_insert(&list, value);
    ck_assert(emlist_contains(&list, value));
    ck_assert(!emlist_contains(&list, (void*)2));
}
END_TEST

START_TEST (test_remove)
{
    LinkedList list;
    emlist_initialize(&list);
    void* value = (void*)1;
    emlist_insert(&list, value);
    ck_assert(emlist_contains(&list, value));
    ck_assert(emlist_remove(&list, value));
    ck_assert(!emlist_contains(&list, value));
}
END_TEST

START_TEST (test_remove_not_in_list)
{
    LinkedList list;
    emlist_initialize(&list);
    void* value = (void*)1;
    emlist_insert(&list, value);
    ck_assert(emlist_contains(&list, value));
    ck_assert(!emlist_remove(&list, (void*)2));
    ck_assert(emlist_contains(&list, value));
}
END_TEST

START_TEST (test_is_empty)
{
    LinkedList list;
    emlist_initialize(&list);
    void* value = (void*)1;
    ck_assert(emlist_is_empty(&list));
    emlist_insert(&list, value);
    ck_assert(!emlist_is_empty(&list));
}
END_TEST

START_TEST (test_clear)
{
    LinkedList list;
    emlist_initialize(&list);
    emlist_insert(&list, (void*)1);
    emlist_insert(&list, (void*)2);
    emlist_insert(&list, (void*)3);
    ck_assert(!emlist_is_empty(&list));
    emlist_clear(&list);
    ck_assert(emlist_is_empty(&list));
}
END_TEST

START_TEST (test_size)
{
    LinkedList list;
    emlist_initialize(&list);
    ck_assert_int_eq(0, emlist_size(&list));
    emlist_insert(&list, (void*)1);
    ck_assert_int_eq(1, emlist_size(&list));
    emlist_insert(&list, (void*)2);
    ck_assert_int_eq(2, emlist_size(&list));
    emlist_insert(&list, (void*)3);
    ck_assert_int_eq(3, emlist_size(&list));
    emlist_clear(&list);
    ck_assert_int_eq(0, emlist_size(&list));
}
END_TEST

START_TEST (test_create)
{
    LinkedList* list = emlist_create();
    ck_assert(list != NULL);
    emlist_destroy(list);
}
END_TEST

Suite* suite(void) {
    Suite* s = suite_create("queue");
    TCase *tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_init);
    tcase_add_test(tc_core, test_insert);
    tcase_add_test(tc_core, test_contains);
    tcase_add_test(tc_core, test_remove);
    tcase_add_test(tc_core, test_remove_not_in_list);
    tcase_add_test(tc_core, test_is_empty);
    tcase_add_test(tc_core, test_clear);
    tcase_add_test(tc_core, test_size);
    tcase_add_test(tc_core, test_create);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int numberFailed;
    Suite* s = suite();
    SRunner *sr = srunner_create(s);
    // Don't fork so we can actually use gdb
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    numberFailed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (numberFailed == 0) ? 0 : 1;
}
