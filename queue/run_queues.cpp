#include "run_queues.h"

void RunQueues::push_by_priority(Process *process)
{
    this->at(process->priority)->push_back(process);
}

CpuProcess *RunQueues::get_prior_process(Process *process, int time_quantum)
{
    for (int i = 0; i < process->priority; i++)
    {
        RunQueue *run_queue = this->at(i);
        if (!run_queue->empty())
        {
            return new CpuProcess(run_queue->pop());
        }
    }
    return new CpuProcess(process, time_quantum);
}

bool RunQueues::check_empty()
{
    bool is_empty = true;
    for (auto iter : *this)
    {
        is_empty = is_empty && iter->empty();
    }
    return is_empty;
}