#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Object.h"
#include <map>
#include <string>

class ResourceManager
{
private:
    static ResourceManager* _RM_Instance;
    ResourceManager();
    ResourceManager(const ResourceManager&);
    ResourceManager& operator=(const ResourceManager&);
    ~ResourceManager();
    bool FindResource(const std::string& label);
    void AddResource(const std::string& label);
    std::map <std::string,Object*> _res_map;
    unsigned int _resource_counter;

public:
    static ResourceManager * Instance();
    Object* GetResource(const std::string& label);//label

};

#endif // RESOURCEMANAGER_H
