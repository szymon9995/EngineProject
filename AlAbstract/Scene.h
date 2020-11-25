#pragma once

class Scene
{
private:

public:
    virtual void OnCreate() {};//wirtualna metoda tworzenia sceny
    virtual void OnDestroy() {};//wirtualna metoda niszczenia sceny
    virtual void Draw() {};//wirtualna metoda rysowania sceny
    virtual void Update() {};//wirtualny funckja aktualizacji sceny
    virtual ~Scene() {};//wirtualny dekonstruktor sceny
};
