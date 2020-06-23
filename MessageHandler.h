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
 * \date Last update: 2020-06-23
*/
class MessageHandler
{
public:
    /*! Checks if build data can be added
     * \param l - List with build data
     * \param libraryBaseName - The library base name
     * \param nD - The new buld data to check
     * \throws QPair<Notice*,NoticeFlag>
    */
    static void errorAddBuldData(QList<BuildDataP> l,QString libraryBaseName,BuildDataP nD);
    /*! Returns a message for build data being added
     * \returns Notice*
    */
    static Notice* addBuildData(BuildDataP d);

    /*! Checks if build data can be updated
     * \param l - List with build data
     * \param libraryBaseName - The library base name
     * \param oldDataPos - The old data position in the data list
     * \param oD - The old build data
     * \param nD - The updated build data to check
     * \throws QPair<Notice*,NoticeFlag>
    */
    static void errorUpdateBuildData(QList<BuildDataP> l,QString libraryBaseName,int oldDataPos,BuildDataP oD,BuildDataP nD);
    /*! Returns a message for build data being updated
     * \returns Notice*
    */
    static Notice* updateBuildData(BuildDataP oD,BuildDataP nD);

    /*! Returns a message for build data being removed
     * \returns Notice*
    */
    static Notice* removeBuildData(BuildDataP d);

    /*! Checks if an exclud path can be added
     * \param l - List of excluded paths
     * \param headerPath - The header path
     * \param excludePath - The new exclude path
     * \throws QPair<Notice*,NoticeFlag>
    */
    static void errorAddExcludePath(QList<QString> l,QString headerPath,QString excludePath);

    /*! Checks if selection can be done
     * \param size - The build data list size
     * \param selected - The amount of data selected
     * \param update - Fi the selection is for updating data
     * \throws QPair<Notice*,NoticeFlag>
    */
    static void errorSelection(int size,int selected,bool update);

    /*! Checks if collection can be preformed
     * \param outpuPt - The output path
     * \param libraryBaseName - The library base name
     * \param headerP - The header path
     * \param builds - The build data list size
     * \throws QPair<Notice*,NoticeFlag>
    */
    static void errorCollectionPreform(QString outputP,QString libraryBaseName,QString headerP,int builds);
    /*! Checks if the collection was preformed without anny errors/warnings
     * \param outpuPt - The output path
     * \param libraryBaseName - The library base name
     * \param headerP - The header path
     * \param data - The build data
     * \throws QPair<Notice*,NoticeFlag>
    */
    static void errorCollection(QString outputP,QString libraryBaseName,QString hederPath,BuildDataP data);
    /*! Collection is done
     * \param outpuPt - The output path
     * \param libraryBaseName - The library base name
     * \param headerP - The header path
     * \param data - The build data
     * \returns Notice*
    */
    static Notice* collection(QString outputP,QString libraryBaseName,QString hederPath,BuildDataP data);

    /*! Data is saved / loaded
     * \param path - Path the data was saved to
     * \param fileName - The files name
     * \param save - If the message is for data being saved
     * \returns Notice*
    */
    static Notice* saveLoadData(QString path,QString fileName,bool save);

};
#endif // MESSAGEHANDLER_H
