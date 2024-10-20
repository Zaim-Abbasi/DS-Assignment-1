// resources.h:
#pragma once
// Zaim Abbasi 22I-2462 B
// Adeel Haider 22I-2568 B
class resource
{
private:
    bool reachedDestination;
    bool Car;
    int score;

public:
    resource()
    {
        reachedDestination = false;
        Car = false;
        score = 0;
    }

    bool getReachedDestination()
    {
        return reachedDestination;
    }

    void setReachedDestination(bool reachedDestination)
    {
        this->reachedDestination = reachedDestination;
    }

    bool getCar()
    {
        return Car;
    }

    void setCar(bool Car)
    {
        this->Car = Car;
    }

    int getScore()
    {
        return score;
    }

    void setScore(int score)
    {
        this->score = score;
    }
};
