#include "input.h"

Input::Input ()
{
}
Input::~Input ()
{
}
void Input::key_callback (GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action)
    {
        m_key = key;
    }
}