#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0) {
        /* fork 실패 */
        perror("fork");
        return 1;
    } else if (pid == 0) {
        /* 자식 프로세스 */
        printf("child: pid=%d, ppid=%d\n", getpid(), getppid());
    } else {
        /* 부모 프로세스: 자식 종료 대기 */
        wait(NULL);
        printf("parent: pid=%d, child=%d\n", getpid(), pid);
    }
    return 0;
}
