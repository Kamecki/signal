#include <fstream>  
#include <time.h>
#include <ctime>
#include <iostream>
using namespace std;
float temps_dech=30;
float val1[10000*30];
int delay =1;
clock_t timemes[sizeof val1];
clock_t t;
int main()
{

    time_t tstart, tend;
    tstart = time(0);
    for (int i = 0; i <sizeof(val1); i++)//je sais pas encore si on def le temps d'aquisition avant ?
    {
        t = clock();
        val1[i] = rand() % 100;
        timemes[i] = (t);
        while (clock() - t < delay);
    }
    tend = time(0); 
    cout << "It took " << difftime(tend, tstart) << " second(s)." << endl;

    std::ofstream datafile("firsttest.txt",std::ofstream::app);

    for (int j = 0; j< sizeof(val1); j++)
    {
        datafile << "Time:" << timemes[j] << " Value:" << val1[j] << "\n";
    }
    datafile.close();

   

}