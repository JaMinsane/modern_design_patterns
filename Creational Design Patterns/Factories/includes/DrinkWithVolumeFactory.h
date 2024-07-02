#pragma once
#include <string>
#include <map>
#include <functional>
#include <memory>
#include "HotDrink.h"

using namespace std;

//Functional Factory

class DrinkWithVolumeFactory
{
    map<string, function<unique_ptr<HotDrink>()>> factories;

public:

    DrinkWithVolumeFactory()
    {
        factories["tea"] = [] {
            auto tea = make_unique<Tea>();
            tea->prepare(200);
            return tea;
            };
    }

    unique_ptr<HotDrink> make_drink(const string& name);
};

inline unique_ptr<HotDrink> DrinkWithVolumeFactory::make_drink(const string& name)
{
    return factories[name]();
}