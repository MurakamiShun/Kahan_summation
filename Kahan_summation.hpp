#pragma once

template<typename F>
class Kahan_summation{
private:
    F sum = static_cast<F>(0.0);
    F c = static_cast<F>(0.0);
public:
    Kahan_summation(F init){
        sum = init;
        c = 0.0;
    }
    Kahan_summation& operator=(F init){
        sum = init;
        c = 0.0;
        return *this;
    }
    Kahan_summation& operator+=(F add){
        const F y = add - c;
        const F t = sum + y;
        c = (t - sum) - y;
        sum = t;
        return *this;
    }
    operator F(){
        return sum;
    }
};