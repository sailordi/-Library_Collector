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

void MessageHandler::collectionCheck(QPair<QString,QString> output,QString headerP,QString releaseP,QString debugP) {
    QString tmp = "";

        if(output.first.isEmpty() == true) {
          tmp.append("Output path is missing");
          tmp.append(Helper::newRow(2) );
        }
        if(output.second.isEmpty() == true) {
          tmp.append("Output name is missing");
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

        if(releaseP.isEmpty() == true && debugP.isEmpty() == true) {
          tmp.append("Release and debug path is missing, only one can be missing");
          tmp.append(Helper::newRow(2) );
        }

        if(tmp.isEmpty() == false) {
          throw QPair<Notice*,NoticeFlag>(new Notice(tmp),NoticeFlag::ERROR);
        }
        bool rP = false,dP = false;

        if(releaseP.isEmpty() == false && QDir(releaseP).exists() == false) {
            tmp.append("Release path no longer exist");
            tmp.append(Helper::newRow(2) );
            rP = true;
        }
        if(debugP.isEmpty() == false && QDir(debugP).exists() == false) {
            tmp.append("Debug path no longer exist");
            tmp.append(Helper::newRow(2) );
            dP = true;
        }

        if(rP == true && dP == true) {
            throw QPair<Notice*,NoticeFlag>(new Notice(tmp),NoticeFlag::ERROR);
        }
        else {
            throw QPair<Notice*,NoticeFlag>(new Notice(tmp),NoticeFlag::WARNING);
        }

}

Notice* MessageHandler::collection() {
    return new Notice("The collection has been performed");
}

Notice* MessageHandler::saveLoadData(QString path,QString fileName,bool save) {
    QString str = Helper::newRow(2)+"Path: "+path+Helper::newRow(2)+"File name: "+fileName+Helper::newRow(2);

        if(save == true) {
            return new Notice("Data has been saved"+str);
        }
        return new Notice("Data has been loaded"+str);

}
