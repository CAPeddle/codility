
#pragma once

/*
    Out put is a list of IDs

    https://github.com/bethrobson/Head-First-Design-Patterns/blob/master/src/headfirst/designpatterns/decorator/starbuzz/Milk.java
    https://raw.githubusercontent.com/ajitpal/BookBank/master/%5BO%60Reilly.%20Head%20First%5D%20-%20Head%20First%20Design%20Patterns%20-%20%5BFreeman%5D.pdf
    https://refactoring.guru/design-patterns/decorator

    
    https://www.tutorialspoint.com/design_pattern/interpreter_pattern.htm

*/

#include "Entity.h"

class Query {
private:

public:
    Query(/* args */){};
    virtual ~Query(){};

    virtual bool match(const Entity entity) = 0;
};


class TypeQuery : public Query {
private:
    EntityType m_type{EntityType::Unknown};

public:
    TypeQuery(/* args */){};
    virtual ~TypeQuery(){};

    virtual void configureEntityType(const EntityType type){
        m_type = type;
    };

    virtual bool match(const Entity entity) override {
            if (entity.type == m_type) {
                return true;
            }
        return false;
    };
};


class HeightPropertyValueQuery : public Query
{
private:
    /* data */
    std::unique_ptr<Query> m_query;
public:
    HeightPropertyValueQuery(std::unique_ptr<Query> query) : m_query(std::move(query)) {};
    virtual ~HeightPropertyValueQuery(){};

// , PropertyValueType type = PropertyValueType::Number 
//needs to be of Type number


    virtual bool match(const Entity entity) override {
            if (entity.height.numberValue > 1) {
                return true;
            }
        return false;
    };

};


