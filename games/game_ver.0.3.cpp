#include <iostream>
#include <vector>
#include <random>

class Ocean; 

class Object {
public:
    enum class Type { STONE, REEF, PREY, PREDATOR, APEX_PREDATOR };

    Object(Type type) : type(type) {}

    virtual void tick(Ocean& ocean) = 0;

protected:
    Type type;
};

class Stone : public Object {
public:
    Stone() : Object(Type::STONE) {}

    void tick(Ocean& ocean) override;
};

class Reef : public Object {
public:
    Reef() : Object(Type::REEF) {}

    void tick(Ocean& ocean) override;
};

class Prey : public Object {
public:
    Prey() : Object(Type::PREY) {}

    void tick(Ocean& ocean) override;
};

class Predator : public Object {
public:
    Predator() : Object(Type::PREDATOR) {}

    void tick(Ocean& ocean) override;
};

class ApexPredator : public Object {
public:
    ApexPredator() : Object(Type::APEX_PREDATOR) {}

    void tick(Ocean& ocean) override;
};

class Ocean {
public:
    Ocean(size_t width, size_t height) : width(width), height(height), grid(width * height), rng(std::random_device()()) {
        initialize();
    }

    void tick();

private:
    size_t width, height;
    std::vector<Object*> grid;
    std::mt19937 rng; 

    void initialize();
    void clearGrid();
    void placeObject(Object::Type type, size_t x, size_t y);
    Object::Type getRandomObjectType();
    size_t getRandomPosition();
};

void Ocean::initialize() {
    // Place some initial objects in the ocean
    for (size_t i = 0; i < width * height / 10; ++i) {
        Object::Type type = getRandomObjectType();
        size_t x = getRandomPosition();
        size_t y = getRandomPosition();
        placeObject(type, x, y);
    }
}

void Ocean::clearGrid() {
    for (Object* obj : grid) {
        delete obj;
    }
    grid.clear();
}

void Ocean::placeObject(Object::Type type, size_t x, size_t y) {

    Object* obj = nullptr;
    switch (type) {
        case Object::Type::STONE:
            obj = new Stone();
            break;
        case Object::Type::REEF:
            obj = new Reef();
            break;
        case Object::Type::PREY:
            obj = new Prey();
            break;
        case Object::Type::PREDATOR:
            obj = new Predator();
            break;
        case Object::Type::APEX_PREDATOR:
            obj = new ApexPredator();
            break;
    }
    grid[y * width + x] = obj;
}

Object::Type Ocean::getRandomObjectType() {
    return static_cast<Object::Type>(rng() % 5);
}

size_t Ocean::getRandomPosition() {
    return rng() % width;
}

void Ocean::tick() {
    for (Object* obj : grid) {
        obj->tick(*this);
    }
}
