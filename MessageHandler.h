#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QPair>
#include <QString>

#include "Message/Notice/Notice.h"
#include "Message/Notice/NoticeFlag.h"

#include "Data/BuildDataTypedefs.h"

typedef QPair<Notice*,NoticeFlag> NoticePair;

/*! \class MessageHandler
 * \brief The class handle all of the messages
 *
 * Incudes: Notice, NoticeFlag.h, BuildDataTypedefs.h
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2020-06-08
 * \date Last update: 2020-06-08
*/
class MessageHandler
{
public:
    /*! Checks if build data can be added
     * \param l - List with build data
     * \param libraryName - The library base name
     * \param nD - The new buld data to ckeck
     * \throws QPair<Notice*,NoticeFlag>
    */
    static void errorAddBuldData(QList<BuildDataP> l,QString libraryBaseName,BuildDataP nD);
    /*! Returns a message for build data being added being successful
     * \returns Notice*
    */
    static Notice* addBuildData(BuildDataP d);

    /*! Checks if collection can be done
     * \param output - The output path / name
     * \param headerP - The header path
     * \param releseP - The relese path
     * \param debugP - The debug path
     * \throws QPair<Notice*,NoticeFlag>
    */
    static void collectionCheck(QPair<QString,QString> output,QString headerP,QString releaseP,QString debugP);

    /*! Collection is done
     * \returns Notice*
    */
    static Notice* collection();

    /*! Data is saved / loaded
     * \param path - Path the data was saved to
     * \param fileName - The files name
     * \param save - If the message is for data being saved
     * \returns Notice*
    */
    static Notice* saveLoadData(QString path,QString fileName,bool save);

};
#endif // MESSAGEHANDLER_H
