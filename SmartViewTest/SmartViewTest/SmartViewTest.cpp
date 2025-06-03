/*
    _________  .___    _____                   .__   .__           ___.    __________                         
    \______   \|   |  /     \    ____    ____  |  |  |  |  _____   \_ |__  \____    /  ____    ____    _____  
    |    |  _/ |   | /  \ /  \ _/ ___\  /  _ \ |  |  |  |  \__  \   | __ \   /     /  /  _ \  /  _ \  /     \ 
    |    |   \ |   |/    Y    \\  \___ (  <_> )|  |__|  |__ / __ \_ | \_\ \ /     /_ (  <_> )(  <_> )|  Y Y  \
    |______  / |___|\____|__  / \___  > \____/ |____/|____/(____  / |___  //_______ \ \____/  \____/ |__|_|  /
           \/               \/      \/                          \/      \/         \/                      \/ 
    Copyright © KUBUS 2024

    We ask you to design and implement a query engine for processing Building Information Modeling(BIM) data. 

    

    Case:
    You can find a dataset containing entities and properties of an example model in `DataSet.h`.
    
    An entity can be any kind of element of a model like a window, a wall, a beam, a door, etc...
    Entities have standardized required properties like an Id, a type or height.
    Additionally, entities can also have optional 'named properties' like 'fire rating' or 'material'.

    Properties can be identified by name and come in different types like numerical, textual or logical values.

    Acceptance criteria:
    1. The engine should be able to process user defined queries and compute the outcome a specific model.
    2. Additionally, the engine should be able to process multiple queries in sequence, 
            meaning that the output, depending on the type of query, can be used a input for the next query.


    Exercises:
    Below are some questions that should help get you going, 
        some of them are already implemented, but the implementation is not great.

    1. Compute the result of a query that returns the id of all entities of type 'wall' with a height larger than 1 meter.
    2. Compute the result of a query that sums the volume of all entities with material 'concrete'.
    3. Compute the result of a query that sums the cost of all entities of type 'wall' with a 'fire rating' of '30' and a 'height' smaller than .7 meters
    4. Given the following queries:
        query A: all entities of type 'wall' with a height larger than 1 meter
        query B: all entities of any type with 'isExternal' set to 'true'
        query C: all entities of type 'beam' with material 'steel'
        query D: sum the volume of all entities
       Please compute the results of the following composed queries:
        A and B
        A or C
        (A and B) or C
        sum the cost of all entities returned by: (A and B) or C
        list all unique cost groups of: (A and B) or C
    5. How would you handle errors in the dataset?
    6. How would you improve the performance if you had 1 dataset, N queries and a very large model (millions of entities)?

*/

#include <iostream>
#include <set>

#include "Helpers.h"
#include "DataSet.h"
#include "Query.h"


void All_Entities_Of_Type_Wall_Taller_Than_1m()
{
    const auto dataset = GetDataSet();

    std::set<size_t> ids;

    TypeQuery baseQuery;
    baseQuery.configureEntityType(EntityType::Wall);
    

    for (const auto& e : dataset.entities)
    {
        if (baseQuery.match(e))
        {
            if (e.height.numberValue > 1)
            {
                ids.insert(e.id);
            }
        }
    }

    std::cout << "ids ";
    for (const size_t id : ids) {
        std::cout << " " << id;
    }
    std::cout << std::endl;
    AssertSetEqual({ 1 }, ids);
}

/*
void All_Entities_Of_Type_Wall_Taller_Than_1m()
{
    const auto dataset = GetDataSet();

    std::set<size_t> ids;

    for (const auto& e : dataset.entities)
    {
        if (e.type == EntityType::Wall)
        {
            if (e.height.numberValue > 1)
            {
                ids.insert(e.id);
            }
        }
    }

    std::cout << "ids ";
    for (const size_t id : ids) {
        std::cout << " " << id;
    }
    std::cout << std::endl;
    AssertSetEqual({ 1 }, ids);
}
*/

void Sum_Volume_All_Entities_Concrete()
{
    const auto dataset = GetDataSet();

    double totalVolume = 0;

    for (const auto& e : dataset.entities)
    {
        for (const auto& prop : e.properties)
        {
            if (prop.name == "material")
            {
                if (prop.value[0].stringValue == "concrete")
                {
                    totalVolume += e.volume.numberValue;
                }
            }
        }
    }

    std::cout << "totalVolume " << totalVolume << std::endl;
    AssertTrue(totalVolume == 49.55);
}

void Sum_Cost_All_Walls_Fire_Rating_30_Height_Below_07()
{
    double totalCost = 0;

    AssertTrue(totalCost == 193.25);
}

int main()
{
    std::cout << "Testing question 1: " << std::endl;
    All_Entities_Of_Type_Wall_Taller_Than_1m();

    std::cout << "Testing question 2: " << std::endl;
    Sum_Volume_All_Entities_Concrete();

    std::cout << "Testing question 3: " << std::endl;
    Sum_Cost_All_Walls_Fire_Rating_30_Height_Below_07();

    std::cout << "Testing question 4: " << std::endl;
    std::cout << "... " << std::endl;

    return 0;
}
