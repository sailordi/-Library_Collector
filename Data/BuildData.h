#ifndef BUILDDATA_H
#define BUILDDATA_H

#include <QObject>
#include <QString>
#include <QStringList>

/*! \class BuildData
 * \brief The class contains library build data [builds name, relese path and debug path]
 *
 * Incudes: QObject, QString & QStringList
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2020-06-10
 * \date Last update: 2020-06-10
*/
class BuildData : public QObject
{
    Q_OBJECT
public:
    /*! Constructor
     * \param parent - The parent [Default: nullptr]
    */
    explicit BuildData(QObject* parent = nullptr);
    /*! Constructor
     * \param data - The list of data
     * \param parent - The parent [Default: nullptr]
    */
    explicit BuildData(QStringList data,QObject *parent = nullptr);

private:
    QString v_buildName = "",v_debugPath = "",v_releasePath = "";

};
#endif // BUILDDATA_H
