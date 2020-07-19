#ifndef OSGHUD_H
#define OSGHUD_H

#include "osgincludes.h"

osg::Geode* createHud();

/*class HudElement:public osg::Geode
{
float f_z_value;
float f_transparency;
bool b_hidden = false;

public:
    Hudelement();

    loadTexture(std::string path);
    getBoundingBox(osg::Geometry boundingBox);


};

class HudGroup:public osg::Group
{
public:
    HudGroup();
    void addElement(HudElement element);
    bool hideElement(std::string elementId);
    bool showElement(std::string elementId);
};

class HudMaster
{
    std::vector<HudGroup> uiGroups;
public:
    HudMaster();
    bool loadHudFile(std::string path);
}*/
#endif // OSGHUD_H
