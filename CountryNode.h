#ifndef __COUNTRYNODE_H_
#define __COUNTRYNODE_H_

#include<iostream>
#include<string>
using namespace;

struct CountryNode
{
    string name;
    int population;

    CountryNode(string Name = "Noname", int p = 0) : name(Name), population(p){}

    CountryNode &operator=(CountryNode &copy)
    {
        name = copy.name;
        population = copy.population;
        return (*this);
    }

    ostream &Output(ostream &out) const
    {
        out << "村名: " << name << "人口: " << population;
        return out;
    }
};

ostream& operator<<(ostream& out, const CountryNode& c)
{
    c.Output(out);
    return out;
}

#endif