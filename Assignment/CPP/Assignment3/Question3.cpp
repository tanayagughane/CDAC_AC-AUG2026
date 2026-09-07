/*
 * Question3.cpp
 *
 *  Created on: Sep 2, 2026
 *      Author: Administrator
 */

#include <iostream>
#include <string>
#include <memory>
#include <utility>

using namespace std;

class Texture {
private:
    string name;
    int width;
    int height;

public:
    // Constructor
    Texture(string n, int w, int h) : name(n), width(w), height(h) {
        cout << "[Texture Loaded]" << endl;
    }

    // Destructor
    ~Texture() {
        cout << "[Texture Released]" << endl;
    }

    // Const member function to display dimensions
    void display() const {
        cout << "Texture: " << name << " (" << width << "x" << height << ")" << endl;
    }
};

int main3() {
    // 1. Create a Texture using make_unique
    auto tex1 = make_unique<Texture>("player_sprite", 512, 512);

    // 2. Call display() through the unique_ptr
    tex1->display();

    // 3. Attempt to copy the unique_ptr:
    // unique_ptr<Texture> tex2 = tex1;
    // Explanation: unique_ptr deletes the copy constructor to enforce exclusive ownership, so direct copying causes a compilation error.

    // 4. Transfer ownership to a second unique_ptr using std::move()
    unique_ptr<Texture> tex2 = move(tex1);
    cout << "tex1 is null: " << (tex1 == nullptr ? "YES" : "NO") << endl;

    // 5. tex2 goes out of scope here -> observe destructor
    return 0;
}





