#include "ResourceManager.h"

#include "Resources.h"
#include "Image.h"
#include <iostream>

ResourceManager* ResourceManager::_RM_Instance = 0;

ResourceManager* ResourceManager::Instance(){

if(!_RM_Instance)
    _RM_Instance = new ResourceManager;
return _RM_Instance;

}

ResourceManager::ResourceManager(){
_resource_counter = 0;
}

ResourceManager::~ResourceManager(){
for( auto it: _res_map )
{
    delete it.second;
}
}

bool ResourceManager::FindResource(const std::string& label){
std::map<std::string,Object*>::iterator it;
it = _res_map.find(label);
if(it!=_res_map.end())
    return true;
return false;
}

void ResourceManager::AddResource(const std::string& label)
{
std::string path = "Assets/Images/" + label;
_res_map[label] = Resources::LoadImage (path);
_resource_counter++;
std::cout<<_resource_counter;
}

Object* ResourceManager::GetResource(const std::string& label){
if(!FindResource(label))
    AddResource(label);

return _res_map[label];
}
