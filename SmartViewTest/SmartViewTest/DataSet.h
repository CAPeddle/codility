#pragma once

#include "Entity.h"

struct DataSet {
    std::vector<Entity> entities;
};

inline DataSet GetDataSet() {
    DataSet ds;

    // clang-format off
    ds.entities = {
        EntityBuilder(0, EntityType::Wall)
            .WithHeight(1)
            .WithVolume(3.5)
            .Add(NamedPropertyValueBuilder("is external").AddBoolValue(true).Build())
            .Add(NamedPropertyValueBuilder("material").AddStringValue("concrete").Build())
            .Build(),
        EntityBuilder(1, EntityType::Wall)
            .WithHeight(2)
            .WithVolume(1.25)
            .Add(NamedPropertyValueBuilder("is external").AddBoolValue(true).Build())
            .Add(NamedPropertyValueBuilder("material").AddStringValue("concrete").Build())
            .Build(),
        EntityBuilder(2, EntityType::Window)
            .WithHeight(2)
            .WithVolume(1)
            .Add(NamedPropertyValueBuilder("is external").AddBoolValue(false).Build())
        .Build(),
        EntityBuilder(3, EntityType::Door)
            .WithHeight(2)
            .WithVolume(1)
            .Add(NamedPropertyValueBuilder("is external").AddBoolValue(false).Build())
            .Add(NamedPropertyValueBuilder("fire rating").AddStringValue("30").Build())
            .Build(),
        EntityBuilder(4, EntityType::Wall)
            .WithHeight(.6)
            .WithVolume(1)
            .Add(NamedPropertyValueBuilder("fire rating").AddStringValue("30").Build())
            .Add(NamedPropertyValueBuilder("material").AddStringValue("wood").Build())
            .Add(NamedPropertyValueBuilder("cost").AddNumberValue(193.25).Build())
            .Add(NamedPropertyValueBuilder("is external").AddBoolValue(true).Build())
            .Build(),
        EntityBuilder(5, EntityType::Wall)
            .WithHeight(.9)
            .WithVolume(1)
            .Add(NamedPropertyValueBuilder("fire rating").AddStringValue("30").Build())
            .Add(NamedPropertyValueBuilder("material").AddStringValue("wood").Build())
            .Add(NamedPropertyValueBuilder("cost").AddNumberValue(73.3).Build())
            .Add(NamedPropertyValueBuilder("is external").AddBoolValue(true).Build())
            .Build(),
        EntityBuilder(6, EntityType::Beam)
            .WithHeight(1.0)
            .WithVolume(2)
            .Add(NamedPropertyValueBuilder("is external").AddBoolValue(true).Build())
            .Add(NamedPropertyValueBuilder("material").AddStringValue("steel").Build())
            .Build(),
        EntityBuilder(7, EntityType::Slab)
            .WithHeight(11.2)
            .WithVolume(44.8)
            .Add(NamedPropertyValueBuilder("is external").AddBoolValue(true).Build())
            .Add(NamedPropertyValueBuilder("material").AddStringValue("concrete").Build())
            .Build(),
        EntityBuilder(8, EntityType::Stairs)
            .WithHeight(10.12)
            .WithVolume(9.96)
            .Add(NamedPropertyValueBuilder("is external").AddBoolValue(false).Build())
            .Add(NamedPropertyValueBuilder("material").AddStringValue("wood").Build())
            .Build(),
        EntityBuilder(9, EntityType::Column)
            .WithHeight(26.80)
            .WithVolume(8.6)
            .Add(NamedPropertyValueBuilder("is external").AddBoolValue(true).Build())
            .Add(NamedPropertyValueBuilder("material").AddStringValue("brick").Build())
            .Build(),
        EntityBuilder(10, EntityType::Beam)
            .WithHeight(0.56)
            .WithVolume(2.36)
            .Add(NamedPropertyValueBuilder("is external").AddBoolValue(false).Build())
            .Add(NamedPropertyValueBuilder("material").AddStringValue("steel").Build())
            .Build(),
    };
    // clang-format on

    return ds;
}
