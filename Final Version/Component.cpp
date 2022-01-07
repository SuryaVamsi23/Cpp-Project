#include "Component.hpp"

Component::Component(string s)
{
    type = s;
    isActiveComponent = false;
}
void Component::setActive()
{
    isActiveComponent = true;
}
void Component::setInactive()
{
    isActiveComponent = false;
}
string Component::get_type()
{
    return (type);
}
