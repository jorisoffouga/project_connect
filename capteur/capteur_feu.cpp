
/*!
* \file capteur_feu.cpp
* \brief Gestion du capteur feu et LED 7 segments et communication MQTT
* \author Thomas Abgrall
* \date 15.11.2019
* \version 0.1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
using namespace std; 

string data_file_sensor = "/home/thomas/Bureau/fichier_gpio";


/**
 * @brief function read data in file
 * 
 * @param signum 
 */
void periodic_task(int signum)
{
    ifstream file(data_file_sensor); // like to the file

    if(file) // control 
    {
        string ligne;   
        while(getline(file, ligne))
        {
            cout << ligne << endl;
        }
    }
    else
    {
        cout << "ERROR: Impossible to open the file." << endl;
    }
}

/**
 * @brief Initialisation timer to read file
 * 
 */
void init_timer()
{
    struct sigaction sa;
    struct itimerval timer;

    /* Install periodic_task  as the signal handler for SIGVTALRM. */
    memset (&sa, 0, sizeof (sa));
    sa.sa_handler = &periodic_task ;
    sigaction (SIGVTALRM, &sa, NULL);

    /* Configure the timer to expire after 100 msec... */
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 100000;

    /* ... and every 250 msec after that. */
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 100000;

    setitimer (ITIMER_VIRTUAL, &timer, NULL);     /* Start a virtual timer. It counts down whenever this process is executing. */

}

/**
 * @brief function main
 * 
 * @return int 
 */
int main()
{
    unsigned int microseconds;

    init_timer(); // initialisation timer to read data file
    
    usleep(microseconds); // sleep to do nothing
    while (1); /* Do busy work. */
}
