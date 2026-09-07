/*
 * Question5.cpp
 *
 *  Created on: Sep 2, 2026
 *      Author: Administrator
 */


#include <iostream>
#include <memory>
#include <string>

using namespace std;

class AudioClip
{
private:
    string name;
    double duration;

public:
    AudioClip(string n, double d)
    {
        name = n;
        duration = d;

        cout << "[AudioClip Loaded]" << endl;
    }

    ~AudioClip()
    {
        cout << "[AudioClip Released]" << endl;
    }

    string getName() const
    {
        return name;
    }
};

int main5()
{
    // 1. Create AudioClip using shared_ptr
    auto audio = make_shared<AudioClip>("explosion", 3.5);

    // 2. Create weak_ptr from shared_ptr
    weak_ptr<AudioClip> observer = audio;

    // 3. Use lock() to access AudioClip
    if (auto clip = observer.lock())
    {
        cout << "Clip alive: " << clip->getName() << endl;
    }

    // 4. Reset shared_ptr - AudioClip gets unloaded
    audio.reset();

    // 5. Check whether weak_ptr is expired
    if (observer.expired())
    {
        cout << "Clip already unloaded." << endl;
    }

    return 0;
}


