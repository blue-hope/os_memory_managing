#ifndef VIRTUAL_MEMORY
#define VIRTUAL_MEMORY

#include "virtual_page_table.h"

using namespace std;

class VirtualMemory
{
public:
    VirtualPageTable page_table;
    int page_id = 0;

    VirtualMemory() {}

    VirtualMemory(int size)
    {
        page_table = VirtualPageTable(size);
    }

    int allocate(int _size)
    {
        page_table.allocate(page_id, _size);
        page_id++;
        return page_id - 1;
    }

    void release(int _allocation_id)
    {
        page_table.release(_allocation_id);
    }

    void print_page_id(int pid)
    {
        printf(">> pid(%d)%-20s", pid, " Page Table(PID): ");
        int cnt = 1;
        printf("|");
        for (auto iter : page_table)
        {
            string page_id = iter->page_id == FREE ? "-" : to_string(iter->page_id);
            printf("%s", page_id.c_str());
            if (cnt % 4 == 0)
                printf("|");
            cnt++;
        }
        printf("\n");
    }

    void print_allocation_id(int pid)
    {
        printf(">> pid(%d)%-20s", pid, " Page Table(AID): ");
        int cnt = 1;
        printf("|");
        for (auto iter : page_table)
        {
            string allocation_id = iter->allocation_id == FREE ? "-" : to_string(iter->allocation_id);
            printf("%s", allocation_id.c_str());
            if (cnt % 4 == 0)
                printf("|");
            cnt++;
        }
        printf("\n");
    }

    void print_valid(int pid)
    {
        printf(">> pid(%d)%-20s", pid, " Page Table(Valid): ");
        int cnt = 1;
        printf("|");
        for (auto iter : page_table)
        {
            string valid = iter->valid == FREE ? "-" : to_string(iter->valid);
            printf("%s", valid.c_str());
            if (cnt % 4 == 0)
                printf("|");
            cnt++;
        }
        printf("\n");
    }

    void print_ref(int pid)
    {
        printf(">> pid(%d)%-20s", pid, " Page Table(Ref): ");
        int cnt = 1;
        printf("|");
        for (auto iter : page_table)
        {
            string ref = iter->ref == FREE ? "-" : to_string(iter->ref);
            printf("%s", ref.c_str());
            if (cnt % 4 == 0)
                printf("|");
            cnt++;
        }
    }
};

#endif