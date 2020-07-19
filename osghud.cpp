#include "osghud.h"

enum hudElementType
{
    button = 0,
    text = 1,
    menu = 2,
    toolbar = 3,
    dropdown = 4
};

osg::Geode* createHud()
{
        osg::ref_ptr<osg::Geode> geode = new osg::Geode;
        osg::ref_ptr<osgText::Text> text = new  osgText::Text;
        geode->addDrawable( text );
        osg::Vec3 position(500.0f,500.0f,0.0f);

        //text->setFont(timesFont);
        text->setFontResolution(10,10);
        text->setPosition(position);
        text->setColor(osg::Vec4(1.0f,1.0f,0.0f,0.2f));
        text->setText("Head Up are good");

        osg::BoundingBox bb;
        bb.expandBy(text->getBoundingBox());

        osg::ref_ptr<osg::Geometry> box = new osg::Geometry;

        osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
        float depth = bb.zMin()-0.1;
        vertices->push_back(osg::Vec3(bb.xMin(),bb.yMax(),depth));
        vertices->push_back(osg::Vec3(bb.xMin(),bb.yMin(),depth));
        vertices->push_back(osg::Vec3(bb.xMax(),bb.yMin(),depth));
        vertices->push_back(osg::Vec3(bb.xMax(),bb.yMax(),depth));
        box->setVertexArray(vertices.get());

        geode->addDrawable(box);

        osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
        normals->push_back(osg::Vec3(0.0f,0.0f,1.0f));
        box->setNormalArray(normals, osg::Array::BIND_OVERALL);

        osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
        colors->push_back(osg::Vec4(0.0f,0.0,1.0f,0.2f));
        box->setColorArray(colors, osg::Array::BIND_OVERALL);

        box->addPrimitiveSet(new osg::DrawArrays(GL_QUADS,0,4));

        osg::ref_ptr<osg::StateSet> ss = box->getOrCreateStateSet();
        ss->setMode(GL_BLEND,osg::StateAttribute::ON);
        //ss->setAttribute(new osg::PolygonOffset(1.0f,1.0f),osg::StateAttribute::ON);
        ss->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);


        return geode.release();
}
