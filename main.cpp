#include <iostream>
#include <string>

using namespace std;

class Pizza{
private:
    static const int DEFAULT_CRUST = 5;
    string name;
    string type;
    int crust;

    float diameter;
    int cost;
    int totalRating;
    int numberOfVotes = 0;

protected:
    bool isForVegan = false;

public:
    Pizza(string name, float diameter, int cost, string type, int ct = DEFAULT_CRUST)
    : name(name), diameter(diameter), type(type), crust(ct), cost(cost){
        totalRating = 0;
    };

    void print()
    {
        cout << name << " " <<type << ":"<< cost<< " rub"<<endl;
    }

    void vote(int vote)
    {
        if (vote > 5 || vote < 1){
            throw std::logic_error("rating must be between 1 and 5");
        }
        totalRating += vote;
        numberOfVotes++;
    }

    int getRating()
    {
        return numberOfVotes == 0 ? 5 : (totalRating / numberOfVotes);
        if (!numberOfVotes){
            return 5;
        }
    }
};

class VeganPizza : /*public, protected, private*/ Pizza{
public:
    VeganPizza(string name, float diameter, int cost, string type) : Pizza(name, diameter, cost, type) {
        isForVegan = true;
    }

    void hack(){
        //this->name = "lol";
    }
};

int main()
{
    Pizza pepperoni("peperoni", 30, 400, "italian");
    Pizza *cheese4 = new Pizza("4cheezes", 30, 320, "american", 15);
    return 0;
}
