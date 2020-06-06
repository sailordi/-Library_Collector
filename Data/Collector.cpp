#include "Collector.h"

//Public functions
Collector::Collector(QString fromPath,QString toPath,QStringList suffix,bool createDirs) {
    this->v_fromPath = fromPath;
    this->v_toPath = toPath;
    this->v_suffix = suffix;
    this->v_createDirs = createDirs;
}

Collector::~Collector() {

}

bool Collector::canCollect() {
    if(this->v_fromPath.isEmpty() == true) {
        return false;
    }
    if(this->v_toPath.isEmpty() == true) {
        return false;
    }
    if(this->v_toPath.compare(SLASH) == 0) {
        return false;
    }

    return true;
}

