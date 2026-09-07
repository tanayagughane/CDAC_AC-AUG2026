/*
 * question4.cpp
 *
 *  Created on: Sep 2, 2026
 *      Author: Administrator
 */

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Shader
{
private:
    string name;
    string type;

public:
    // Constructor
    Shader(string n, string t)
    {
        name = n;
        type = t;

        cout << "[Shader Compiled]" << endl;
    }

    // Destructor
    ~Shader()
    {
        cout << "[Shader Destroyed]" << endl;
    }

    // Returns reference count
    int getReferenceCount(shared_ptr<Shader> ptr) const
    {
        return ptr.use_count();
    }
};

int main4()
{
    // 1. Create Shader using make_shared
    auto shader = make_shared<Shader>("main_vert", "vertex");

    // Reference count = 1
    cout << "Ref count: " << shader.use_count() << endl;

    {
        // 2. Assign same shared_ptr to renderer
        auto rendererRef = shader;

        // Reference count = 2
        cout << "Ref count: " << shader.use_count() << endl;

        // 3. Assign same shared_ptr to editor
        auto editorRef = shader;

        // Reference count = 3
        cout << "Ref count: " << shader.use_count() << endl;
    }

    // rendererRef and editorRef destroyed
    // Reference count becomes 1
    cout << "Ref count: " << shader.use_count() << endl;

    return 0;
}


