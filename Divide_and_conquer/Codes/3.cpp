#include<bits/stdc++.h>
using namespace std;

class Side
{
public:
    Side(){}
    Side(int small, int large) {
        small_ = small;
        large_ = large;
    }
    int small_, large_;
};

class RiverCrossingSimulator
{
public:
    RiverCrossingSimulator() {
        right_ = Side(0, 0);
        left_ = Side(2, 2);
        state_ = 1;
    }

    void simulate() {
        output += "State" + to_string(state_) + ": " + get_sides() + "\n";
        move_larges_to_right();
        move_smalls_to_right();
        output = "Solution: " + to_string(state_ - 1) + "\n" + output; 
        cout << output;
    }

    void move_larges_to_right() {
        if(left_.large_ == 0) 
            return;
        
        if(right_.small_ == 0)
            move_small_one_to_right();
        
        move_large_one_to_right();

        move_larges_to_right();
    }

    void move_smalls_to_right() {
        if(left_.small_ == 0)
            return;
        
        move_small_one_to_right();

        move_smalls_to_right();
    }

    void move_small_one_to_right() {
        left_.small_ -= 2;
        right_.small_ += 2;

        output += report_state(false);
        
        if(left_.small_ == 0 && left_.large_ == 0)
            return;

        left_.small_++;
        right_.small_--;

        output += report_state(true);
    }

    string report_state(bool is_left) {
        state_++;
        string action_str =(is_left) ? "Action: Left\n" : "Action: Right\n";
        return action_str + "State" + to_string(state_) + ": " + get_sides() + "\n";
    }

    void move_large_one_to_right() {
        left_.large_--;
        right_.large_++;

        output += report_state(false);

        right_.small_--;
        left_.small_++;

        output += report_state(true);
    }

    string get_sides() {
        string res = "";
        ostringstream ss;

        ss << "[";
        for (int i = 0; i < left_.large_ + left_.small_; i++)
        {
            ss << ((i < left_.large_) ? "\'L\'" : "\'S\'");
            if(i + 1 != left_.large_ + left_.small_)
                ss << ", ";
        }
        ss << "]";

        ss << "[";
        for (int i = 0; i < right_.large_ + right_.small_; i++)
        {
            ss << ((i < right_.large_) ? "\'L\'" : "\'S\'");
            if(i + 1 != right_.large_ + right_.small_)
                ss << ", ";
        }
        ss << "]";

        return ss.str();
    }
private:
    Side right_, left_;
    int state_;
    string output;
};

int main()
{
    RiverCrossingSimulator river_crossing_simulator = RiverCrossingSimulator();
    river_crossing_simulator.simulate();
    return 0;
}
