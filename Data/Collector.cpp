#include "Collector.h"

#include <QDir>
#include <QFileInfo>

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

QString Collector::formatOutPath(QString dirPath,QString dirName) {
    if(dirPath.isEmpty() == false && dirPath.at(dirPath.size()-1) == SLASH.at(0) ) {
        dirPath.resize(dirPath.size()-1);
    }

    if(dirPath.isEmpty() == true) {
        return "";
    }
    if(dirName.isEmpty() == true) {
        return dirPath+SLASH;
    }

    return dirPath+SLASH+dirName+SLASH;
}

void Collector::createPath(QString path) {
    QDir d(path);

        if(d.exists() == false) {
            d.mkdir(path);
        }
}

//Private functions
void Collector::dir(QFileInfo i) {
    if(i.isDir() == false) {
        return;
    }

    QString n = (this->v_createDirs == false) ? "" : i.baseName();
    QString toP = Collector::formatOutPath(this->v_toPath,n);
    QString fromP = i.absolutePath()+SLASH+i.baseName()+SLASH;

    if(this->v_createDirs == true) {
        Collector::createPath(toP);
    }


}

void Collector::file(QFileInfo i) {
    if(i.isFile() == false || (i.isFile() == true && this->v_suffix.contains(i.suffix() ) == false) ) {
        return;
    }

    QString n = i.baseName()+"."+i.suffix();
    QFile* tF = new QFile(this->v_toPath+n);

    if(tF->exists() == true) {
        tF->remove();
    }

    delete tF;

    QFile fF(this->v_fromPath+n);

    fF.copy(this->v_toPath+n);
}
