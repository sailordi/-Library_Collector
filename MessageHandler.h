#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QPair>
#include <QString>

#include "Message/Notice/Notice.h"
#include "Message/Notice/NoticeFlag.h"

/*! \class MessageHandler
 * \brief The class handle all of the messages
 *
 * Incudes: Notice & NoticeFlag.h
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

};
#endif // MESSAGEHANDLER_H
