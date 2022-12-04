#include "types.h"
#include "user.h"
int main(int argc, char *argv[])
{
    int nInt = 30;
    for (int i = 0; i < nInt; i++)
    {
        int pid = 0;
        if (getpid() == 3)
        {
            fork();
        }
        if (getpid() == 3)
        {
            wait();
        }
        for (int j = 0; j <= 100; j++)
        {
            if (getpid() == 3)
            {
                wait();
            }
            else
            {
                if (pid % 3 == 0)
                {
                    for (int m = 0; m < 10000000; m++)
                    {
                    }
                }
                if (pid % 3 == 1)
                {
                    for (int m = 0; m < 1000; m++)
                    {
                    }
                    yield();
                }
                if (pid % 3 == 2)
                {
                    sleep(1);
                }
            }
        }
    }

    int *retime = 0;
    int *rutime = 0;
    int *stime = 0;

    if (getpid() % 3 == 0)
    {
        printf(1, "PID: %d CPU-BOUND\n", getpid());
    }
    if (getpid() % 3 == 1)
    {
        printf(1, "PID: %d S-BOUND\n", getpid());
    }
    if (getpid() % 3 == 2)
    {
        printf(1, "PID: %d IO-BOUND\n", getpid());
    }

    if (getpid() == 3)
    {
        set_total(nInt);
    }

    wait2(retime, rutime, stime);

    exit();
}
