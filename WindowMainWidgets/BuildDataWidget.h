#ifndef BUILDDATAWIDGET_H
#define BUILDDATAWIDGET_H

#include "Base/LayoutWidget/MultiLayoutWidget.h"

#include <QSharedDataPointer>

class QLineEdit;
class QTextEdit;
class QPushButton;

class BuildData;

/*! \class BuildDataWidget
 * \brief The class contains widgets for adding/updating the build data
 *
 * Incudes: MultiLayoutWidget & QSharedDataPointer
 *
 * Forward declarations: QLineEdit, QTextEdit & QPushButton
 *
 * Inherits: MultiLayoutWidget
 *
 * \author Created by: Sailordi
 * \author Last to touch it: Sailordi
 *
 * \date Created: 2020-06-11
 * \date Last update: 2020-06-11
*/
class BuildDataWidget : public MultiLayoutWidget
{
    Q_OBJECT
public:
    /*! Constructor
     * \param l - The layout for the build data widgets
     * \param parent - The parent [Default: nullptr]
    */
    explicit BuildDataWidget(QGridLayout* l,QWidget *parent = nullptr);

private:
    QLineEdit* v_buildNameE = nullptr;
    QTextEdit* v_debugPathE = nullptr,*v_releasePathE = nullptr;
    QPushButton* v_debugPathB = nullptr,*v_releasePathB = nullptr;
    QPushButton* v_resetBuildNameB = nullptr,*v_resetDebugPathB = nullptr,*v_resetReleasePathB = nullptr;

    QSharedPointer<BuildData> v_oldBuildData;

};
#endif // BUILDDATAWIDGET_H
