#ifndef TIMER_H
#define TIMER_H


struct LTimer
{
    //The clock time when the timer started
    int StartTicks;

    //The ticks stored when the timer was paused
    int PausedTicks;

    //The timer status
    bool Paused;
    bool Started;

    //Initialize
    LTimer();

    //Actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    int getTicks();

    //Checks the status of the timer
    bool isStarted();
    bool isPaused();

    void gameOver();
};

#endif // TIMER_H
