#include "MessageHandler.h"

#include <QDir>
#include <QFileInfo>

#include "Base/Other/Helper.h"

//Public functions
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

        if(releaseP.isEmpty() == false && QDir(releaseP).exists() == false) {
            tmp.append("Release path no longer exist");
            tmp.append(Helper::newRow(2) );
        }
        if(debugP.isEmpty() == false && QDir(debugP).exists() == false) {
            tmp.append("Debug path no longer exist");
            tmp.append(Helper::newRow(2) );
        }

        if(tmp.isEmpty() == false) {
          throw QPair<Notice*,NoticeFlag>(new Notice(tmp),NoticeFlag::ERROR);
        }

}

Notice* MessageHandler::collection() {
    return new Notice("The collection has been performed");
}
