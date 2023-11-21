#include "fruit.h"
#include "apple.h"
#include "watermelon.h"
#include "Granny_Smith.h"

using namespace std;

void print_fruit_info(Fruit& f)
{
    cout << "Fruit Name: " << f.get_name() << endl;
    cout << "Color: " << f.get_color() << endl;
    cout << "Price: " << f.get_unitPrice() << endl;
    cout << "Calculated Price: " << f.calculate_price() << endl << endl << endl;
}

int main()
{

    Apple a("Apple","Red",2.2,2,true);
    print_fruit_info(a);

    vector <Fruit *> fruit_vector;

    fruit_vector.push_back(new Apple("Apple","Red",2.2,2,true));
    fruit_vector.push_back(new Watermelon("Watermelon","Green",2.2,true));
    fruit_vector.push_back(new Granny_Smith("Granny Smith Apple","Green",5.5,2));
    fruit_vector.push_back(new Apple("Apple","Red",2.2,2,true));
    fruit_vector.push_back(new Watermelon("Watermelon","Green",2.2,true));
    fruit_vector.push_back(new Granny_Smith("Granny Smith Apple","Green",5.5,2));
    fruit_vector.push_back(new Apple("Apple","Red",2.2,2,true));
    fruit_vector.push_back(new Watermelon("Watermelon","Green",2.2,true));
    fruit_vector.push_back(new Granny_Smith("Granny Smith Apple","Green",5.5,2));

    for(int i = 0; i < fruit_vector.size(); i++)
    {
        print_fruit_info(*fruit_vector[i]);
    }
        for(int i = 0; i < fruit_vector.size(); i++)
    {
        delete fruit_vector[i];
    }


    // cout << "Fruit Name: " << a.get_name() << endl;
    // cout << "Color: " << a.get_color() << endl;
    // cout << "Price: " << a.get_unitPrice() << endl;
    // cout << "Weight: " << a.get_weight() << endl;
    // cout << "Sweetness: " << a.get_sweetness() << endl;
    // cout << "Calculated Price: " << a.calculate_price() << endl << endl << endl;


    // /////////////////    /////////////////    /////////////////
    // Watermelon w("Watermelon","Green",2.2,true);

    // cout << "Fruit Name: " << w.get_name() << endl;
    // cout << "Color: " << w.get_color() << endl;
    // cout << "Price: " << w.get_unitPrice() << endl;
    // cout << "Weight: " << w.get_seeds() << endl;
    // cout << "Calculated Price: " << w.calculate_price() << endl << endl << endl;

    // Granny_Smith gs("Granny Smith Apple","Green",5.5,2);

    // cout << "Fruit Name: " << gs.get_name() << endl;
    // cout << "Color: " << gs.get_color() << endl;
    // cout << "Price: " << gs.get_unitPrice() << endl;
    // cout << "Weight: " << gs.get_weight() << endl;
    // cout << "Sweetness: " << gs.get_sweetness() << endl;
    // cout << "Calculated Price: " << gs.calculate_price() << endl;



}