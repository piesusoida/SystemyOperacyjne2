#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Fork{
    pair <int, int> fork_position; // gdzie jest na stole
    mutex used;
};

void philosopher(int id, vector <Fork>& forks) {
    int thinking_time;
    int fork_lower;
    int fork_higher;
    if (forks[id].fork_position.first < forks[id].fork_position.second){ // enumerating the forks to prevent deadlock
        fork_lower = forks[id].fork_position.first;
        fork_higher = forks[id].fork_position.second;
    }
    else{
        fork_higher = forks[id].fork_position.first;
        fork_lower = forks[id].fork_position.second;
    }
    while (true) {
        thinking_time = rand() % 1801 + 200;
        cout << "Philosopher " << id << " is thinking" << endl;
        this_thread::sleep_for(chrono::milliseconds(thinking_time));  

        unique_lock<mutex> lockLeft(forks[fork_lower].used); //podniesienie lewego widelca

        unique_lock<mutex> lockRight(forks[fork_higher].used); // podniesienie prawego widelca

        cout << "Philosopher " << id << " is eating" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000)); 

        lockLeft.unlock(); // oddanie widelcow
        lockRight.unlock();

        cout << "Philosopher " << id << " is full, he starts wasting time thinking" << endl;;
    }
}


int main(){
    srand(time(NULL));
    int number_of_philosophers;
    int temp_input;
    cout << "specify amount of philosophers" << endl;
    cin >> temp_input;
    if (temp_input>1){
        number_of_philosophers = temp_input;
        cout << "number of threads is " << number_of_philosophers << endl;
    }
    else {
        cout << "not correct input: it is not an integer >1, can't eat with less than two forks, philosopher starved";
        return 1;
    }
    vector < Fork > forks(number_of_philosophers);
    vector < thread > philosophers;
    for(int i=0;i<number_of_philosophers;i++){        //creating threads, full lock is prevented by random time of thinking and 
        forks[i].fork_position.first=i;
        forks[i].fork_position.second=(i+1)%number_of_philosophers;
        philosophers.push_back(thread(philosopher, i, ref(forks)));
    }
    for (auto& philosopher : philosophers) { //synchronization
        philosopher.join();
    }



    return 0;
}
