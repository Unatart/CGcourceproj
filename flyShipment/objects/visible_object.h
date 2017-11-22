#ifndef VISIBLE_OBJECT_H
#define VISIBLE_OBJECT_H

#include "scene_object.h"

class visible_object : public scene_object {
    public:
        explicit visible_object() = default;
        visible_object(visible_object&) = delete;
        visible_object(const visible_object&) = delete;
        virtual ~visible_object() = default;

        bool visible() override {
            return true;
        }
};

#endif // VISIBLE_OBJECT_H
