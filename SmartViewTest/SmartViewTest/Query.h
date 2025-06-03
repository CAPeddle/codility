
#pragma once

/*
    Out put is a list of IDs
*/

#include "Entity.h"

class Query {
private:

public:
    Query(/* args */){};
    virtual ~Query(){};

    virtual bool match(const Entity entity) {
        return false;
    }
};


class TypeQuery {
private:
    EntityType m_type{EntityType::Unknown};

public:
    TypeQuery(/* args */){};
    virtual ~TypeQuery(){};

    virtual void configureEntityType(const EntityType type){
        m_type = type;
    };

    virtual bool match(const Entity entity){
            if (entity.type == m_type) {
                return true;
            }
        return false;
    };
};


class HeightPropertyValueQuery : public TypeQuery
{
private:
    /* data */
public:
    HeightPropertyValueQuery(PropertyValueType type = PropertyValueType::Number){};
    ~HeightPropertyValueQuery(){};
};


