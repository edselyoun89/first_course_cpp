#include <iostream>
#include <vector>
#include <random>

class Ocean; // Forward declaration

class Object {
public:
    enum class Type { STONE, REEF, PREY, PREDATOR, APEX_PREDATOR };

    Object(Type type) : type(type) {}
    virtual ~Object() {}

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
        // Initialize the ocean with objects
        // For simplicity, let's randomly place some objects in the ocean
        initialize();
    }

    ~Ocean() {
        clearGrid();
    }

    void tick();

private:
    size_t width, height;
    std::vector<Object*> grid;
    std::mt19937 rng; // Mersenne Twister random number generator

    void initialize();
    void clearGrid();
    void placeObject(Object::Type type, size_t x, size_t y);
    Object::Type getRandomObjectType();
    size_t getRandomPosition();
};

void Stone::tick(Ocean& ocean) {
    // Implement tick behavior for Stone
    // Do something...
}

void Reef::tick(Ocean& ocean) {
    // Implement tick behavior for Reef
    // Do something...
}

void Prey::tick(Ocean& ocean) {
    // Implement tick behavior for Prey
    // Do something...
}

void Predator::tick(Ocean& ocean) {
    // Implement tick behavior for Predator
    // Do something...
}

void ApexPredator::tick(Ocean& ocean) {
    // Implement tick behavior for ApexPredator
    // Do something...
}

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
    // Place the object at the given position
    // For simplicity, we assume the position is valid
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
    // Return a random object type
    // For simplicity, we assume an equal chance for all types
    return static_cast<Object::Type>(rng() % 5);
}

size_t Ocean::getRandomPosition() {
    // Return a random position within the ocean
    return rng() % width;
}

void Ocean::tick() {
    // Perform one time step of the simulation
    // For now, we simply call the tick function of each object
    for (Object* obj : grid) {
        obj->tick(*this);
    }
}
