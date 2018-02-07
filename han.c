#include <stdio.h>
#include <stdlib.h> 
#include <signal.h> // sigaction(), sigsuspend(), sig*()
#include <unistd.h> // alarm()

void handle_signal(int signal);
void handle_sigalrm(int signal);
void do_sleep(int seconds);

int main() {
    struct sigaction sa;

    printf("Working on pid : %d\n", getpid());

    sa.sa_handler = &handle_signal;

    sa.sa_flags = SA_RESTART;

    sigfillset(&sa.sa_mask);

    /*if (sigaction(SIGHUP, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGHUP"); // Should not happen
    }

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGUSR1"); // Should not happen
    }*/

    if (sigaction(SIGKILL, &sa, NULL) == -1) {
        perror("Cannot handle SIGKILL"); // Will always happen
        printf("You can never handle SIGKILL anyway...\n");
    }

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGINT"); // Should not happen
    }

    for (;;) {
        printf("\nSleeping for ~3 seconds\n");
        do_sleep(3); // Later to be replaced with a SIGALRM
    }
}

void handle_signal(int signal) {
    const char *signal_name;
    sigset_t pending;

    switch (signal) {
        /*case SIGHUP:
            signal_name = "SIGHUP";
            break;
        case SIGUSR1:
            signal_name = "SIGUSR1";
            break;*/
        case SIGINT:
            printf("Caught SIGINT, exiting now\n");
            exit(0);
        default:
            fprintf(stderr, "Caught wrong signal: %d\n", signal);
            return;
    }

    printf("Caught %s, sleeping for ~3 seconds\n"
           "Try sending another SIGHUP / SIGINT / SIGALRM "
           "(or more) meanwhile\n", signal_name);
    do_sleep(3);
    printf("Done sleeping for %s\n", signal_name);

    // So what did you send me while I was asleep?
    sigpending(&pending);
    if (sigismember(&pending, SIGHUP)) {
        printf("A SIGHUP is waiting\n");
    }
    if (sigismember(&pending, SIGUSR1)) {
        printf("A SIGUSR1 is waiting\n");
    }

    printf("Done handling %s\n\n", signal_name);
}

void handle_sigalrm(int signal) {
    if (signal != SIGALRM) {
        fprintf(stderr, "Caught wrong signal: %d\n", signal);
    }

    printf("Got sigalrm, do_sleep() will end\n");
}

void do_sleep(int seconds) {
    struct sigaction sa;
    sigset_t mask;
    
    sa.sa_handler = &handle_sigalrm; 
    sa.sa_flags = SA_RESETHAND; 
    sigfillset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);
    
    // Get the current signal mask
    sigprocmask(0, NULL, &mask);

    // Unblock SIGALRM
    sigdelset(&mask, SIGALRM);

    // Wait with this mask
    alarm(seconds);
    sigsuspend(&mask);

    printf("sigsuspend() returned\n");
}
