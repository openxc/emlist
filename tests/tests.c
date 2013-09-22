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
    emlist_insert(&list, value);
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

Suite* suite(void) {
    Suite* s = suite_create("queue");
    TCase *tc_core = tcase_create("core");
    tcase_add_test(tc_core, test_init);
    tcase_add_test(tc_core, test_insert);
    tcase_add_test(tc_core, test_contains);
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
