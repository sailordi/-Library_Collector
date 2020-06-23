#include "MessageHandler.h"

#include <QDir>
#include <QFileInfo>

#include "Base/Other/Helper.h"

#include "Data/BuildData.h"

//Public functions
void MessageHandler::errorAddBuldData(QList<BuildDataP> l,QString libraryBaseName,BuildDataP nD) {
    QString str = "";

        if(nD->buildName().isEmpty() == true) {
            str.append("Build name is empty");
            str.append(Helper::newRow() );
        }
        else if(nD->buildName().isEmpty() == false && nD->buildName().compare(libraryBaseName) == 0) {
            str.append("Build name is the same as library base name");
            str.append(Helper::newRow() );
        }
        if(nD->debugPath().isEmpty() == true && nD->releasePath().isEmpty() == true) {
            str.append("Debug & release path is empty");
            str.append(Helper::newRow() );
        }

        if(nD->debugPath().isEmpty() == false && nD->releasePath().isEmpty() == false
                && nD->debugPath().compare(nD->releasePath() ) == 0 ) {
                str.append("Debug and relese path are the same");
                str.append(Helper::newRow() );
        }

        if(str.isEmpty() == true) {
            bool f = false,d = false,r = false,b  = false;

            for(int i = 0; i < l.size(); i++) {
                BuildDataP bD = l.at(i);

                if(bD->buildName().compare(nD->buildName() ) == 0) {
                    b = true;
                    f = true;
                }
                if(bD->debugPath().compare(nD->debugPath() ) == 0) {
                    d = true;
                    f = true;
                }
                if(bD->releasePath().compare(nD->releasePath() ) == 0) {
                    r = true;
                    f = true;
                }

                if(f == true) {
                    i  = l.size();
                }

            }

            if(b == true) {
                str.append("Build name already exists in the build data list");
                str.append(Helper::newRow() );
            }
            if(d == true) {
                str.append("Debug path already exists in the build data list");
                str.append(Helper::newRow() );
            }
            if(r == true) {
                str.append("Release path already exists in the build data list");
                str.append(Helper::newRow() );
            }

        }

        if(str.isEmpty() == false) {
            throw NoticePair(new Notice(str),NoticeFlag::ERROR);
        }
}

Notice* MessageHandler::addBuildData(BuildDataP d) {
    QString str = "";

        str.append("Build name: "+d->buildName() );
        str.append(Helper::newRow(2) );

        if(d->debugPath().isEmpty() == false) {
            str.append("Debug path: "+Helper::newRow()+d->debugPath() );
        }
        else {
            str.append("Debug path is empty");
        }
        str.append(Helper::newRow() );
        if(d->releasePath().isEmpty() == false) {
            str.append("Release path: "+Helper::newRow()+d->releasePath() );
        }
        else {
            str.append("Release path is empty");
        }
        str.append(Helper::newRow(2) );

        str.append("Was added to build data list");
        str.append(Helper::newRow() );

        return new Notice(str);
}

void MessageHandler::errorUpdateBuildData(QList<BuildDataP> l,QString libraryBaseName,int oldDataPos,BuildDataP oD,BuildDataP nD) {
    QString str = "";
    QStringList oL = {oD->buildName(),oD->debugPath(),oD->releasePath()};
    QStringList nL = {nD->buildName(),nD->debugPath(),nD->releasePath()};
    bool empty = true,same = true;

        for(int i = 0; i < oL.size(); i++) {
            if(nL.at(i).isEmpty() == false) {
                empty = false;
            }
            else {
                nL.replace(i,oL.at(i) );
            }
            if(nL.at(i).compare(oL.at(i) ) != 0) {
                same = false;
            }

        }

        if(empty == true) {
            str.append("No data has been entered");
            str.append(Helper::newRow() );
        }
        if(same == true) {
            str.append("No data has changed");
            str.append(Helper::newRow() );
        }

        if(str.isEmpty() == false) {
            throw NoticePair(new Notice(str),NoticeFlag::ERROR);
        }

        if(nD->buildName().compare(libraryBaseName) == 0) {
            str.append("Build name is the same as library base name");
            str.append(Helper::newRow() );
        }
        if(nD->debugPath().isEmpty() == false && nD->releasePath().isEmpty() == false
                && nD->debugPath().compare(nD->releasePath() ) == 0 ) {
                str.append("Debug and relese path are the same");
                str.append(Helper::newRow() );
        }

        if(str.isEmpty() == false) {
            throw NoticePair(new Notice(str),NoticeFlag::ERROR);
        }
        bool f = false,d = false,r = false,b  = false;
        l.removeAt(oldDataPos);

        for(int i = 0; i < l.size(); i++) {
            BuildDataP bD = l.at(i);

            if(bD->buildName().compare(nD->buildName() ) == 0) {
                b = true;
                f = true;
            }
            if(bD->debugPath().compare(nD->debugPath() ) == 0) {
                d = true;
                f = true;
            }
            if(bD->releasePath().compare(nD->releasePath() ) == 0) {
                r = true;
                f = true;
            }

            if(f == true) {
                i  = l.size();
            }

        }

        if(b == true) {
            str.append("Build name already exists in the build data list");
            str.append(Helper::newRow() );
        }
        if(d == true) {
            str.append("Debug path already exists in the build data list");
            str.append(Helper::newRow() );
        }
        if(r == true) {
            str.append("Release path already exists in the build data list");
            str.append(Helper::newRow() );
        }

        if(str.isEmpty() == false) {
            throw NoticePair(new Notice(str),NoticeFlag::ERROR);
        }

}

Notice* MessageHandler::updateBuildData(BuildDataP oD,BuildDataP nD) {
    QString str = "";

    if(oD->buildName().compare(nD->buildName() ) != 0 && oD->buildName().isEmpty() == true) {
        str.append("Build name was empty is now ");
        str.append(nD->buildName() );
    }
    else if(oD->buildName().compare(nD->buildName() ) != 0 && oD->buildName().isEmpty() == false) {
        str.append("Build name was "+oD->buildName()+" is now ");
        str.append(nD->buildName() );
    }
    else {
        str.append("Build name has not been changed");
    }
    str.append(Helper::newRow(2) );

    if(oD->debugPath().compare(nD->debugPath() ) != 0 && oD->debugPath().isEmpty() == true) {
        str.append("Debug path was empty"+Helper::newRow()+"  is now "+Helper::newRow() );
        str.append(nD->debugPath() );
    }
    else if(oD->debugPath().compare(nD->debugPath() ) != 0 && oD->debugPath().isEmpty() == false) {
        str.append("Debug path was "+Helper::newRow()+oD->debugPath()+Helper::newRow()+" is now "+Helper::newRow() );
        str.append(nD->debugPath() );
    }
    else {
        str.append("Debug path has not been changed");
    }
    str.append(Helper::newRow() );

    if(oD->releasePath().compare(nD->releasePath() ) != 0 && oD->releasePath().isEmpty() == true) {
        str.append("Release path was empty"+Helper::newRow()+"  is now "+Helper::newRow() );
        str.append(nD->releasePath() );
    }
    else if(oD->releasePath().compare(nD->releasePath() ) != 0 && oD->releasePath().isEmpty() == false) {
        str.append("Release path was "+Helper::newRow()+oD->releasePath()+Helper::newRow()+" is now "+Helper::newRow() );
        str.append(nD->releasePath() );
    }
    else {
        str.append("Release path has not been changed");
    }
    str.append(Helper::newRow(2) );

    return new Notice(str);
}

Notice* MessageHandler::removeBuildData(BuildDataP d) {
    QString str = "";

        str.append("Build name: "+d->buildName() );
        str.append(Helper::newRow(2) );

        if(d->debugPath().isEmpty() == false) {
            str.append("Debug path: "+Helper::newRow()+d->debugPath());
        }
        else {
            str.append("Debug path is empty");
        }
        str.append(Helper::newRow() );

        if(d->releasePath().isEmpty() == false) {
            str.append("Release path: "+Helper::newRow()+d->releasePath() );
        }
        else {
            str.append("Release path is empty");
        }
        str.append(Helper::newRow(2) );

        str.append("Was removed from build data list");
        str.append(Helper::newRow() );

        return new Notice(str);
}

void MessageHandler::errorAddExcludePath(QList<QString> l,QString headerPath,QString excludePath) {
    QString str = "";

        if(headerPath.isEmpty() == true) {
            str = "Header path is missing"+Helper::newRow();
        }

        if(str.isEmpty() == true && excludePath.compare(headerPath) == 0) {
            str = "Exclude path is the same as header path"+Helper::newRow(2)
                          +excludePath+Helper::newRow();
        }
        if(str.isEmpty() == true && excludePath.contains(headerPath) == true) {
            str = "Exclude path is not in header path"+Helper::newRow(2)
                          +excludePath+Helper::newRow();
        }

        for(int i = 0; str.isEmpty() == true && i < l.size(); i++) {
            if(l.at(i).compare(excludePath) == 0) {
                str = "Exclude path alredy exist in excluded paths list"+Helper::newRow(2)
                              +excludePath+Helper::newRow();
                break;
            }
        }

        if(str.isEmpty() == false) {
            throw NoticePair(new Notice(str),NoticeFlag::ERROR);
        }

}

void MessageHandler::errorSelection(int size,int selected,bool update) {
    QString str;

        if(size < 0) {
            str = "No build data in list"+Helper::newRow();
        }

        if(str.isEmpty() == true && selected <= 0) {
            str = "No build data has been selected"+Helper::newRow();
        }
        if(str.isEmpty() == true && selected > 1 && update == true) {
            str = "Multiple build data entries has been selected"+Helper::newRow();
        }

        if(str.isEmpty() == false) {
            throw NoticePair(new Notice(str),NoticeFlag::ERROR);
        }
}

void MessageHandler::errorCollectionPreform(QString outputP,QString libraryBaseName,QString headerP,int builds) {
    QString tmp = "";

        if(outputP.isEmpty() == true) {
          tmp.append("Output path is missing");
          tmp.append(Helper::newRow(2) );
        }
        if(libraryBaseName.isEmpty() == true) {
          tmp.append("Library base name is missing");
          tmp.append(Helper::newRow(2) );
        }

        if(headerP.isEmpty() == true) {
          tmp.append("Header path is missing");
          tmp.append(Helper::newRow(2) );
        }
        else if(headerP.isEmpty() == false && QDir(headerP).exists() == false) {
            tmp.append("Header path no longer exist");
            tmp.append(Helper::newRow(2) );
        }

        if(builds <= 0) {
            tmp.append("No build data have been added");
        }

        if(tmp.isEmpty() == false) {
            throw QPair<Notice*,NoticeFlag>(new Notice(tmp),NoticeFlag::ERROR);
        }
}

void MessageHandler::errorCollection(QString outputP,QString libraryBaseName,QString hederPath,BuildDataP data) {
    QString str = "";
    bool r = true,d = true;

        if(data->debugPath().isEmpty() == false && QDir(data->debugPath() ).exists() == false) {
            d = false;
        }
        if(data->releasePath().isEmpty() == false && QDir(data->releasePath() ).exists() == false) {
            r = false;
        }

        if(r == true && d == true) {
            return;
        }

        if(r == false && d == false) {
            str.append("The collection could not be done both debug path and release path could no longer be found");
        }
        else if(r == false && data->debugPath().isEmpty() == true) {
            str.append("The collection could not be done debug path was empty and release path could no longer be found");
        }
        else if(r == false && data->debugPath().isEmpty() == false) {
            str.append("The collection could not be compleatly preformed release path could no longer be found");
        }
        else if(d == false && data->releasePath().isEmpty() == true) {
            str.append("The collection could not be done debug path could no longe be found and release path was empty");
        }
        else if(d == false && data->releasePath().isEmpty() == false) {
            str.append("The collection could not be compleatly preformed debug path could no longer be found");
        }
        str.append(Helper::newRow(2) );

        str.append("Library output path: "+outputP);
        str.append(Helper::newRow() );
        str.append("Library base name: "+libraryBaseName);
        str.append(Helper::newRow(2) ) ;
        str.append("Headers path: "+Helper::newRow()+hederPath);
        str.append(Helper::newRow(2) );

        str.append("Build name: "+data->buildName() );
        str.append(Helper::newRow() );
        if(data->debugPath().isEmpty() == false) {
            str.append("Debug path: "+Helper::newRow()+data->debugPath() );
        }
        str.append(Helper::newRow() );
        if(data->releasePath().isEmpty() == false) {
            str.append("Release path: "+Helper::newRow()+data->releasePath() );
        }
        str.append(Helper::newRow() );

        if(r == false && d == false) {
            throw QPair<Notice*,NoticeFlag>(new Notice(str),NoticeFlag::ERROR);
        }
        else if(r == false && data->debugPath().isEmpty() == true) {
            throw QPair<Notice*,NoticeFlag>(new Notice(str),NoticeFlag::ERROR);
        }
        else if(d == false && data->releasePath().isEmpty() == true) {
            throw QPair<Notice*,NoticeFlag>(new Notice(str),NoticeFlag::ERROR);
        }
        else {
            throw QPair<Notice*,NoticeFlag>(new Notice(str),NoticeFlag::WARNING);
        }

}

Notice* MessageHandler::collection(QString outputP,QString libraryBaseName,QString hederPath,BuildDataP data) {
    QString str = "";

        str.append("Library headers and library files has been collected");
        str.append(Helper::newRow() );
        str.append("Library output path: "+outputP);
        str.append(Helper::newRow() );
        str.append("Library base name: "+libraryBaseName );
        str.append(Helper::newRow(2) ) ;
        str.append("Headers path: "+Helper::newRow()+hederPath);
        str.append(Helper::newRow(2) );

        str.append("Build name: "+data->buildName()+Helper::newRow() );
        if(data->debugPath().isEmpty() == false) {
            str.append("Debug path: "+Helper::newRow()+data->debugPath() );
        }
        else {
            str.append("Debug path is empty");
        }
        str.append(Helper::newRow() );
        if(data->releasePath().isEmpty() == false) {
            str.append("Release path: "+Helper::newRow()+data->releasePath() );
        }
        else {
            str.append("Release path is empty");
        }
        str.append(Helper::newRow() );

        return new Notice(str);
}

Notice* MessageHandler::saveLoadData(QString path,QString fileName,bool save) {
    QString str = Helper::newRow(2)+"Path: "+path+Helper::newRow(2)+"File name: "+fileName+Helper::newRow(2);

        if(save == true) {
            return new Notice("Data has been saved"+str);
        }
        return new Notice("Data has been loaded"+str);

}
