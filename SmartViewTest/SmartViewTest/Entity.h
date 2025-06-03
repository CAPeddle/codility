#pragma once

#include <string>
#include <vector>

using EntityId = size_t;

enum class PropertyValueType { String, Number, Bool, Unknown };

struct PropertyValue {
    PropertyValueType type = PropertyValueType::Unknown;
    std::string stringValue{};
    double numberValue{};
    bool booleanValue = false;
};

struct NamedProperty {
    std::string name{};
    std::vector<PropertyValue> value{};
};

enum class EntityType { Wall, Window, Beam, Slab, Column, Stairs, Door, Unknown };

struct Entity {
    EntityId id{};
    EntityType type = EntityType::Unknown;
    PropertyValue height{};
    PropertyValue volume{};

    std::vector<NamedProperty> properties{};
};

class EntityBuilder {
public:
    EntityBuilder(const EntityId id, const EntityType type) {
        _entity.id   = id;
        _entity.type = type;
    }

    EntityBuilder WithHeight(const double height) {
        _entity.height.type        = PropertyValueType::Number;
        _entity.height.numberValue = height;

        return *this;
    }

    EntityBuilder WithVolume(const double volume) {
        _entity.volume.type        = PropertyValueType::Number;
        _entity.volume.numberValue = volume;

        return *this;
    }

    EntityBuilder Add(const NamedProperty& property) {
        _entity.properties.push_back(property);

        return *this;
    }

    Entity Build() {
        return _entity;
    }

private:
    Entity _entity;
};

class NamedPropertyValueBuilder {
public:
    explicit NamedPropertyValueBuilder(const std::string& name) {
        _prop.name = name;
    }

    NamedPropertyValueBuilder AddStringValue(const std::string& s) {
        PropertyValue val;
        val.stringValue = s;
        val.type        = PropertyValueType::String;
        _prop.value.push_back(val);

        return *this;
    }

    NamedPropertyValueBuilder AddNumberValue(const double num) {
        PropertyValue val;
        val.numberValue = num;
        val.type        = PropertyValueType::Number;
        _prop.value.push_back(val);

        return *this;
    }

    NamedPropertyValueBuilder AddBoolValue(const bool b) {
        PropertyValue val;
        val.booleanValue = b;
        val.type         = PropertyValueType::Bool;
        _prop.value.push_back(val);

        return *this;
    }

    NamedProperty Build() {
        return _prop;
    }

private:
    NamedProperty _prop;
};
